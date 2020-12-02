#include "Mario.h"
#include "FileManager.h"
#include "KeyInput.h"




void Mario::setPos(float x, float y, float z)
{
	position = glm::vec3(x, y, z);
}

void Mario::setRot(float speed, float x, float y, float z)
{
	rotSpeed = speed;
	rotVec = glm::vec3(x, y, z);
}

void Mario::setScale(float x, float y, float z)
{
	scaleVec = glm::vec3(x, y, z);
	if (scaleVec.x != 0.0f || scaleVec.y != 0.0f || scaleVec.z != 0.0f)
	{
		Scale = glm::scale(Scale, scaleVec);
	}
}

void Mario::setCameraPos(float x, float y, float z)
{
	cameraPos = glm::vec3(-x, -y, -z);
}

void Mario::init()
{
	FileManager::GetInstance()->loadingObj(this, "cube.obj", "character.DDS", "20151687_vs.shader", "20151687_fs.shader");
	this->setPos(0, 0, 0);
	this->setCameraPos(0, 0, 0);
	this->setScale(0, 0, 0);	
}

void Mario::render()
{
	glUseProgram(this->programID);


	KeyInput::GetInstance()->computeMatricesFromInputs();

	glm::mat4 ProjectionMatrix = KeyInput::GetInstance()->getProjectionMatrix();
	glm::mat4 ViewMatrix = KeyInput::GetInstance()->getViewMatrix();
	glm::mat4 ModelMatrix = glm::mat4(1.0);
	//glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

	// Send our transformation to the currently bound shader, 
	// in the "MVP" uniform
	//glUniformMatrix4fv(obj->MatrixID, 1, GL_FALSE, &MVP[0][0]);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->Texture);
	glUniform1i(this->textureID, 0);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, this->vertexbuffer);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);


	// 2nd attribute buffer : UVs
	glBindBuffer(GL_ARRAY_BUFFER, this->uvbuffer);
	glVertexAttribPointer(
		1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
		2,                                // size : U+V => 2
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);

	// 3rd attribute buffer : normals
	glBindBuffer(GL_ARRAY_BUFFER, this->normalbuffer);
	glVertexAttribPointer(
		2,                                // attribute
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);



	glm::mat4 movePos = glm::mat4(1.0f);
	movePos = glm::translate(movePos, this->position);

	glm::mat4 moveCameraPos = glm::mat4(1.0f);
	moveCameraPos = glm::translate(moveCameraPos, this->cameraPos);

	glm::mat4 MVP;

	
	if (rotSpeed > 0.0f)
	{
		Rot = glm::rotate(Rot, glm::radians(rotSpeed), rotVec);
	}
		
	

	MVP = ProjectionMatrix * moveCameraPos * ViewMatrix*ComPositScale*ComPositPos *CompositRot * Scale* movePos *Rot * ModelMatrix;


	glUniformMatrix4fv(this->MatrixID, 1, GL_FALSE, &MVP[0][0]);
	glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	for (
		vector<Object*>::const_iterator it = _Table->begin();
		it != _Table->end();
		++it
		)
	{
		(*it)->RotMatrix(Rot);
		(*it)->PosMatrix(movePos);
		(*it)->PosMatrix(Scale);
	}
}

void Mario::update()
{
	
}


void Mario::shutDown()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(MatrixID);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void Mario::add(Object* addObj)
{
	_Table->push_back(addObj);
}

void Mario::RotMatrix(glm::mat4 _rot)
{
	CompositRot = _rot;
}

void Mario::PosMatrix(glm::mat4 _pos)
{
	ComPositPos = _pos;
}

void Mario::ScaleMatrix(glm::mat4 _scale)
{
	ComPositScale = _scale;
}
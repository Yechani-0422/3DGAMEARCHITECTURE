#include "renderObject.h"

GLuint colorbuffer;

GLuint MatrixID;

glm::mat4 MVP;
renderObject::renderObject(string str, string str1, const char * str2, const char * str3)
{
	


	graphicLib::GetInstance()->programID = graphicLib::GetInstance()->LoadShaders(str2, str3);

    MatrixID = glGetUniformLocation(graphicLib::GetInstance()->programID, "MVP");


	glGenVertexArrays(1, &graphicLib::GetInstance()->VertexArrayID);
	glBindVertexArray(graphicLib::GetInstance()->VertexArrayID);



	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);



	glm::mat4 View = glm::lookAt(
		glm::vec3(-5, 3, 5),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
	);


	glm::mat4 To_World = glm::mat4(1.0f);
	MVP = Projection * View * To_World;

	vector<GLfloat> vertex_data = graphicLib::GetInstance()->LoadCsv(str);


	glGenBuffers(1, &graphicLib::GetInstance()->vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, graphicLib::GetInstance()->vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_data.size() * sizeof(GLfloat), vertex_data.data(), GL_STATIC_DRAW);

	vector<GLfloat> color_data = graphicLib::GetInstance()->LoadCsv(str1);

	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, color_data.size() * sizeof(GLfloat), color_data.data(), GL_STATIC_DRAW);
}


renderObject::~renderObject()
{
}

void renderObject::render()
{
	glUseProgram(graphicLib::GetInstance()->programID);
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, graphicLib::GetInstance()->vertexbuffer);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glVertexAttribPointer(
		1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);

	glDrawArrays(GL_TRIANGLES, 0, 3 * 12);

	glDisableVertexAttribArray(0);

	
	
}
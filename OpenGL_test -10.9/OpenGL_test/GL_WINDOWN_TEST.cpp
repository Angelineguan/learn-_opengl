
// Window dimensions


//////////////////////////////////////////////////////////////////////////
#include "RenderData.h"
#include "UpdataCamera.h"
#include "CallBackFunction.h"
//////////////////////////////////////////////////////////////////////////

static  glm::mat4 myview;

GLfloat CurrentFrame=0;
GLfloat LastFrame=0;
// GLfloat DeltaTime;
  
GLFWwindow* window;
// The MAIN function, from here we start the application and run the game loop
struct TotalTransFormMatrix
{
	glm::mat4 view;
	glm::mat4 projection;
	glm::mat4 model;
};

void initialWindowContex()
{
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	//	return 0;
	// Create a GLFWwindow object that we can use for GLFW's functions
	 window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);    

	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	
	}
	glfwMakeContextCurrent(window);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
	
	}    
	std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
	// Init GLFW

//	glfwSetInputMode(window,GLFW_CURSOR,GLFW_CURSOR_DISABLED);
	setCallBackFunctionInContext(window);
//	glfwSetKeyCallback(window,key_callback_updataCamara);
}

int main()
{
	
	initialWindowContex();
	// Define the viewport dimensions
	initialData();
	SetRenderState();
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
	
		CurrentFrame=glfwGetTime();
		DeltaTime=CurrentFrame-LastFrame;
		LastFrame=CurrentFrame;
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		glClearColor(0.2f,0.0f,0.3f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if(is_clear_color)
		{		
			glClearColor(0.2f,1.0f,1.0f,1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		if (press_count==5)
		{		
			glClearColor(0.0f,0.0f,0.3f,1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
			RenderScene();
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}

	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}



#include "AppClass.h"
void Application::InitVariables(void)
{
	// Init spaceInvader with MyMesh Objects
	for (int i = 0; i < siNum; i++) 
	{
		//init the mesh
		m_pMesh = new MyMesh();
		spaceInvader.push_back(m_pMesh);
	}

	for (int i = 0; i < spaceInvader.size(); i++) 
	{
		//m_pMesh->GenerateCube(1.0f, C_WHITE);
		spaceInvader[i]->GenerateCube(1.0f, C_BLACK);
	}
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	matrix4 m4View = m_pCameraMngr->GetViewMatrix();
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	
	matrix4 m4Scale = glm::scale(IDENTITY_M4, vector3(2.0f,2.0f,2.0f));

	// Translation for each mesh row are made for the first cube in each row from the left
	static float value = 0.0f;
	matrix4 m4Translate = glm::translate(IDENTITY_M4, vector3(value, 2.0f, 3.0f));
	matrix4 m4Translate2 = glm::translate(IDENTITY_M4, vector3(1.0f + value, 1.0f, 3.0f));
	matrix4 m4Translate3 = glm::translate(IDENTITY_M4, vector3(value, 0.0f, 3.0f));
	matrix4 m4Translate4 = glm::translate(IDENTITY_M4, vector3(-1.0f + value, -1.0f, 3.0f));
	matrix4 m4Translate5 = glm::translate(IDENTITY_M4, vector3(-2.0f + value, -2.0f, 3.0f));
	matrix4 m4Translate6 = glm::translate(IDENTITY_M4, vector3(-2.0f + value, -3.0f, 3.0f));
	matrix4 m4Translate7 = glm::translate(IDENTITY_M4, vector3(-2.0f + value, -4.0f, 3.0f));
	matrix4 m4Translate8 = glm::translate(IDENTITY_M4, vector3(1.0f + value, -5.0f, 3.0f));
	value += 0.01f;

	// RENDER 'spaceInvader' MESH PROPERLY
	// Run through all the generated cubes within 'spaceInvader' and split them among the rows
	for (int i = 0; i < spaceInvader.size(); i++)
	{
		// Row 1
		if (i < 2)
		{
			spaceInvader[i]->Render(m4Projection, m4View, m4Scale * m4Translate);
			m4Translate = glm::translate(IDENTITY_M4, vector3(6.0f + value, 2.0f, 3.0f));
		}

		// Row 2
		else if (i >= 2 && i < 4)
		{
			spaceInvader[i]->Render(m4Projection, m4View, m4Scale * m4Translate2);
			m4Translate2 = glm::translate(IDENTITY_M4, vector3(5.0f + value, 1.0f, 3.0f));
		}

		// Row 3
		else if (i >= 4 && i < 11)
		{
			spaceInvader[i]->Render(m4Projection, m4View, m4Scale * m4Translate3);
			m4Translate3 = glm::translate(IDENTITY_M4, vector3((i - 3) + value, 0.0f, 3.0f));
		}

		// Row 4
		else if (i >= 11 && i < 19)
		{
			spaceInvader[i]->Render(m4Projection, m4View, m4Scale * m4Translate4);

			if (i == 12)
			{
				m4Translate4 = glm::translate(IDENTITY_M4, vector3(value, -1.0f, 3.0f));
			}
			else if (i >= 13 && i < 16)
			{
				m4Translate4 = glm::translate(IDENTITY_M4, vector3((i - 11) + value, -1.0f, 3.0f));
			}
			else if (i >= 16 && i < 19)
			{
				m4Translate4 = glm::translate(IDENTITY_M4, vector3((i - 10) + value, -1.0f, 3.0f));
			}
		}

		// Row 5
		else if (i >= 19 && i < 30)
		{
			spaceInvader[i]->Render(m4Projection, m4View, m4Scale * m4Translate5);
			m4Translate5 = glm::translate(IDENTITY_M4, vector3((i - 20) + value, -2.0f, 3.0f));
		}

		// Row 6
		else if (i >= 30 && i < 40)
		{
			spaceInvader[i]->Render(m4Projection, m4View, m4Scale * m4Translate6);

			if (i > 30 && i < 38)
			{
				m4Translate6 = glm::translate(IDENTITY_M4, vector3((i - 31) + value, -3.0f, 3.0f));
			}

			if (i == 38)
			{
				m4Translate6 = glm::translate(IDENTITY_M4, vector3(8.0f + value, -3.0f, 3.0f));
			}
		}

		// Row 7
		else if (i >= 40 && i < 44)
		{
			spaceInvader[i]->Render(m4Projection, m4View, m4Scale * m4Translate7);

			if (i == 40)
			{
				m4Translate7 = glm::translate(IDENTITY_M4, vector3(value, -4.0f, 3.0f));
			}
			else if (i == 41)
			{
				m4Translate7 = glm::translate(IDENTITY_M4, vector3(6.0f + value, -4.0f, 3.0f));
			}
			else if (i == 42)
			{
				m4Translate7 = glm::translate(IDENTITY_M4, vector3(8.0f + value, -4.0f, 3.0f));
			}
		}

		// Row 8
		else if (i >= 44 && i < 48)
		{
			spaceInvader[i]->Render(m4Projection, m4View, m4Scale * m4Translate8);

			if (i == 44)
			{
				m4Translate8 = glm::translate(IDENTITY_M4, vector3(2.0f + value, -5.0f, 3.0f));
			}

			if (i >= 45)
			{
				m4Translate8 = glm::translate(IDENTITY_M4, vector3((i - 41) + value, -5.0f, 3.0f));
			}
		}
	}

	//matrix4 m4Model = m4Translate * m4Scale;
	//matrix4 m4Model = m4Scale * m4Translate;

	//m_pMesh->Render(m4Projection, m4View, m4Model);
	
	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();
	
	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	// Deallocate each element in 'spaceInvader'
	for (int i = 0; i < spaceInvader.size(); i++)
	{
		if (spaceInvader[i] != nullptr)
		{
			delete spaceInvader[i];
			spaceInvader[i] = nullptr;
		}
		SafeDelete(spaceInvader[i]);
	}

	//release GUI
	ShutdownGUI();
}
﻿#include "main.h"
#include "ImGui/imgui_internal.h"

CMenu* pMenu;

void CMenu::Update()
{
	if (!FrontEndMenuManager.m_bMenuActive)
	{
		if (bOpen)
		{
			fFadeAlpha = min(fFadeAlpha + ImGui::GetIO().DeltaTime * 6.0f, 1.0f);
			ImGui::GetStyle().Alpha = fFadeAlpha;
			pSAMP->toggleSAMPCursor(1);
			ImGui::GetIO().MouseDrawCursor = true;
		}
		else if (iToggle == 0)
		{
			fFadeAlpha = 0.f;
			pSAMP->toggleSAMPCursor(0);
			ImGui::GetIO().MouseDrawCursor = false;
			iToggle = 3;
		}
	}
	else if (bOpen) pSAMP->toggleSAMPCursor(0);
}

void CMenu::Theme()
{
	ImGuiStyle& style = ImGui::GetStyle();

	style.Alpha = 1.0f;
	style.WindowPadding = { 8, 8 };
	style.WindowMinSize = { 32, 32 };
	style.WindowRounding = 3.0f;
	style.PopupRounding = 3.0f;
	style.WindowTitleAlign = { 0.5f, 0.5f };

	style.FramePadding = { 4, 3 };
	style.FrameRounding = 3.3f;
	style.ChildRounding = 5.0f;
	style.ItemSpacing = { 8, 4 };
	style.TouchExtraPadding = { 0, 0 };
	style.IndentSpacing = 21.0f;
	style.ColumnsMinSpacing = 0.0f;
	style.ScrollbarSize = 6.0f;
	style.ScrollbarRounding = 0.0f;
	style.GrabMinSize = 5.0f;
	style.GrabRounding = 3.3f;
	style.ButtonTextAlign = { 0.5f, 0.5f };
	style.DisplayWindowPadding = { 22, 22 };
	style.DisplaySafeAreaPadding = { 4, 4 };
	style.AntiAliasedLines = true;
	style.AntiAliasedFill = true;
	style.CurveTessellationTol = 1.f;

	switch (g_Config.g_Style.iTheme)
	{
	case 0:
	{
		g_Config.g_Style.vecTheme[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_TextDisabled] = ImVec4(0.70f, 0.71f, 0.74f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_WindowBg] = ImVec4(0.11f, 0.13f, 0.16f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_ChildBg] = ImVec4(0.16f, 0.17f, 0.20f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_PopupBg] = ImVec4(0.16f, 0.17f, 0.20f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_Border] = ImVec4(0.12f, 0.12f, 0.16f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_FrameBg] = ImVec4(0.09f, 0.10f, 0.15f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_FrameBgHovered] = ImVec4(0.12f, 0.13f, 0.17f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_FrameBgActive] = ImVec4(0.07f, 0.08f, 0.13f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_TitleBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_TitleBgActive] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_TitleBgCollapsed] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_ScrollbarBg] = ImVec4(0.17f, 0.17f, 0.17f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_ScrollbarGrab] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_CheckMark] = ImVec4(0.86f, 0.87f, 0.90f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_SliderGrab] = ImVec4(0.48f, 0.49f, 0.51f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_SliderGrabActive] = ImVec4(0.66f, 0.67f, 0.69f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_Button] = ImVec4(0.09f, 0.10f, 0.15f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_ButtonHovered] = ImVec4(0.12f, 0.13f, 0.17f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_ButtonActive] = ImVec4(0.07f, 0.08f, 0.13f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_Header] = ImVec4(0.29f, 0.34f, 0.43f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_HeaderHovered] = ImVec4(0.21f, 0.24f, 0.31f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_HeaderActive] = ImVec4(0.29f, 0.34f, 0.43f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
		g_Config.g_Style.vecTheme[ImGuiCol_SeparatorHovered] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
		g_Config.g_Style.vecTheme[ImGuiCol_SeparatorActive] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
		g_Config.g_Style.vecTheme[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
		g_Config.g_Style.vecTheme[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
		g_Config.g_Style.vecTheme[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
		g_Config.g_Style.vecTheme[ImGuiCol_Tab] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_TabHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_TabActive] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
		g_Config.g_Style.vecTheme[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 0.25f, 0.25f, 0.50f);
		g_Config.g_Style.vecTheme[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		g_Config.g_Style.vecTheme[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		g_Config.g_Style.vecTheme[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		g_Config.g_Style.vecTheme[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
		g_Config.g_Style.vecTheme[ImGuiCol_Logo] = ImVec4(1.f, 1.f, 1.f, 1.f);
		break;
	}
	case 1:
	{
		ImGui::StyleColorsDark();
		break;
	}
	case 2:
	{
		ImGui::StyleColorsLight();
		break;
	}
	case 3:
	{
		ImGui::StyleColorsClassic();
		break;
	}
	case 4:
	{
		g_Config.g_Style.vecTheme[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_TextDisabled] = ImVec4(0.70f, 0.71f, 0.74f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_WindowBg] = ImVec4(0.09f, 0.09f, 0.09f, 0.98f);
		g_Config.g_Style.vecTheme[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_PopupBg] = ImVec4(0.09f, 0.09f, 0.09f, 0.98f);
		g_Config.g_Style.vecTheme[ImGuiCol_Border] = ImVec4(0.00f, 0.51f, 0.09f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_FrameBg] = ImVec4(0.21f, 0.21f, 0.21f, 0.94f);
		g_Config.g_Style.vecTheme[ImGuiCol_FrameBgHovered] = ImVec4(0.25f, 0.25f, 0.25f, 0.94f);
		g_Config.g_Style.vecTheme[ImGuiCol_FrameBgActive] = ImVec4(0.17f, 0.17f, 0.17f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.51f, 0.09f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 0.51f, 0.09f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
		g_Config.g_Style.vecTheme[ImGuiCol_MenuBarBg] = ImVec4(0.21f, 0.21f, 0.21f, 0.94f);
		g_Config.g_Style.vecTheme[ImGuiCol_ScrollbarBg] = ImVec4(0.26f, 0.26f, 0.26f, 0.94f);
		g_Config.g_Style.vecTheme[ImGuiCol_ScrollbarGrab] = ImVec4(0.00f, 0.51f, 0.09f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.10f, 0.61f, 0.19f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.20f, 0.71f, 0.29f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_CheckMark] = ImVec4(0.00f, 0.51f, 0.09f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_SliderGrab] = ImVec4(0.10f, 0.61f, 0.19f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_SliderGrabActive] = ImVec4(0.20f, 0.71f, 0.29f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_Button] = ImVec4(0.00f, 0.51f, 0.09f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_ButtonHovered] = ImVec4(0.10f, 0.61f, 0.19f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.71f, 0.29f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_Header] = ImVec4(0.00f, 0.51f, 0.09f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_HeaderHovered] = ImVec4(0.10f, 0.61f, 0.19f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.71f, 0.29f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_Separator] = ImVec4(0.00f, 0.51f, 0.09f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.61f, 0.19f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_SeparatorActive] = ImVec4(0.20f, 0.71f, 0.29f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.51f, 0.09f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_ResizeGripHovered] = ImVec4(0.10f, 0.61f, 0.19f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_ResizeGripActive] = ImVec4(0.20f, 0.71f, 0.29f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_Tab] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_TabHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_TabActive] = ImVec4(0.00f, 0.51f, 0.09f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_PlotLines] = ImVec4(0.00f, 0.51f, 0.09f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_PlotLinesHovered] = ImVec4(0.10f, 0.61f, 0.19f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_PlotHistogram] = ImVec4(0.00f, 0.51f, 0.09f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_PlotHistogramHovered] = ImVec4(0.10f, 0.61f, 0.19f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
		g_Config.g_Style.vecTheme[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		g_Config.g_Style.vecTheme[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		g_Config.g_Style.vecTheme[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		g_Config.g_Style.vecTheme[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		g_Config.g_Style.vecTheme[ImGuiCol_ModalWindowDimBg] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);
		break;
	}
	}

	for (int i = 0; i < ImGuiCol_COUNT; i++)
		ImGui::GetStyle().Colors[i] = g_Config.g_Style.vecTheme[i];
}

void CMenu::ActiveButton()
{
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.f, 0.f, 0.f, 0.f));
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.f, 0.f, 0.f, 0.f));
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.f, 0.f, 0.f, 0.f));
	ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyleColorVec4(ImGuiCol_Text));
}

void CMenu::NormalButton()
{
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.f, 0.f, 0.f, 0.f));
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.f, 0.f, 0.f, 0.f));
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.f, 0.f, 0.f, 0.f));
	ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled));
}

void CMenu::Tooltip(const char* szText)
{
	if (strlen(szText) && ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::TextUnformatted(szText);
		ImGui::EndTooltip();
	}
}

void CMenu::RenderMap()
{
	if (isKeyDown('Z'))
	{
		ImVec2 vecWindow((ImGui::GetIO().DisplaySize.x - ImGui::GetIO().DisplaySize.y) / 2, 0);
		int iMapX = 0, iMapY = 0;

		for (auto i = 0; i < 144; i++)
		{
			if (i != 0 && i % 12 == 0)
			{
				iMapX = 0;
				iMapY++;
			}
			ImVec2 vecMapMin(vecWindow.x + vecWindow.y + ImGui::GetIO().DisplaySize.y / 12.f * iMapX, vecWindow.y + ImGui::GetIO().DisplaySize.y / 12.f * iMapY);
			ImVec2 vecMapMax(vecWindow.x + vecWindow.y + ImGui::GetIO().DisplaySize.y / 12.f * (iMapX + 1), vecWindow.y + ImGui::GetIO().DisplaySize.y / 12.f * (iMapY + 1));
			if (pTextures->tMap[i]->raster)
				ImGui::GetBackgroundDrawList()->AddImage(pTextures->tMap[i], vecMapMin, vecMapMax, { 0, 0 }, { 1, 1 }, ImColor(255, 255, 255, 150));
			iMapX++;
		}

		for (auto i = 0; i < SAMP_MAX_GANGZONES; i++)
		{
			if (!pSAMP->getInfo()->pPools->pGangzone->iIsListed[i])
				continue;

			float* fTurfPos = pSAMP->getInfo()->pPools->pGangzone->pGangzone[i]->fPosition;
			CVector vecTurfMin(fTurfPos[0], fTurfPos[1], 0), vecTurfMax(fTurfPos[2], fTurfPos[3], 0), vecTurfMinScreen, vecTurfMaxScreen;
			Utils::CalcMapToScreen(vecWindow, &vecTurfMin, &vecTurfMinScreen, ImGui::GetIO().DisplaySize.y);
			Utils::CalcMapToScreen(vecWindow, &vecTurfMax, &vecTurfMaxScreen, ImGui::GetIO().DisplaySize.y);

			bool bAltColor = false;
			ULONGLONG ulTick = GetTickCount64();
			if (GetTickCount64() - ulTick >= 500)
			{
				bAltColor = !bAltColor;
				ulTick = GetTickCount64();
			}
			pRender->DrawRectFilled({ vecTurfMinScreen.x, vecTurfMinScreen.y, 0 }, { vecTurfMaxScreen.x, vecTurfMaxScreen.y, 0 }, bAltColor ? pSAMP->getInfo()->pPools->pGangzone->pGangzone[i]->dwColor : pSAMP->getInfo()->pPools->pGangzone->pGangzone[i]->dwAltColor);
		}

		for (size_t i = 0; i < MAX_RADAR_TRACES; i++)
		{
			auto pBlip = CRadar::ms_RadarTrace[i];

			switch (pBlip.m_nBlipType)
			{
			case BLIP_COORD:
			case BLIP_CONTACTPOINT:
			{
				if (pBlip.m_nRadarSprite < 5)
					break;

				CVector vecBlipScreen;
				Utils::CalcMapToScreen(vecWindow, &pBlip.m_vecPos, &vecBlipScreen, ImGui::GetIO().DisplaySize.y);
				ImGui::GetBackgroundDrawList()->AddImage(((CSprite2d*)(4 * pBlip.m_nRadarSprite + 0xBAA250))->m_pTexture, { vecBlipScreen.x - 10, vecBlipScreen.y - 10 }, { vecBlipScreen.x + 10, vecBlipScreen.y + 10 });
				break;
			}
			}
		}

		CVector vecCentreScreen;
		Utils::CalcMapToScreen(vecWindow, &FindPlayerPed()->GetPosition(), &vecCentreScreen, ImGui::GetIO().DisplaySize.y);
		pRender->DrawImageRotated(((CSprite2d*)(4 * RADAR_SPRITE_CENTRE + 0xBAA250))->m_pTexture, { vecCentreScreen.x,vecCentreScreen.y }, { 10, 10 }, -FindPlayerPed()->m_fCurrentRotation);
	}
}

void CMenu::Render()
{
	if (!pMenu->bOpen) return;

	ImGui::SetNextWindowSize({ 600, 424 });
	ImGui::SetNextWindowPos({ ImGui::GetIO().DisplaySize.x * 0.5f, ImGui::GetIO().DisplaySize.y * 0.5f }, ImGuiCond_Once, { 0.5f, 0.5f });

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 16, 16 });
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, { 1, 0 });
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 3.0f);
	ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 14, -10 });

	if (ImGui::Begin("STEALTH", &bOpen, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar))
	{
		ImGui::BeginGroup();
		ImGui::Dummy({ 0, 2 });
		ImGui::Text("FormDX");
		ImGui::Text("github: iAldrich23xX");
		//ImGui::Image(pTextures->tLogo, { 109, 21 }, { 0, 0 }, { 1, 1 }, ImGui::GetStyle().Colors[ImGuiCol_Logo]);
		ImGui::EndGroup();
		ImVec2 vecWindow = ImGui::GetWindowPos();
		ImGui::GetWindowDrawList()->AddRectFilled({ vecWindow.x + 147, vecWindow.y + 16 }, { vecWindow.x + 148, vecWindow.y + 41 }, ImColor(48, 54, 64, 255));
		ImGui::SameLine(170);

		ImGui::TabButton("Weapon", &iCurrentTab, 0, { 0, 25 }); ImGui::SameLine();
		ImGui::TabButton("Player", &iCurrentTab, 1, { 0, 25 }); ImGui::SameLine();
		ImGui::TabButton("Visual", &iCurrentTab, 2, { 0, 25 }); ImGui::SameLine();
		ImGui::TabButton("Style", &iCurrentTab, 3, { 0, 25 }); ImGui::SameLine();
		ImGui::TabButton("Extra", &iCurrentTab, 4, { 0, 25 }); ImGui::SameLine();
		if (ImGui::TabButton("Settings", &iCurrentTab, 5, { 0, 25 }))
			ImGui::OpenPopup("Settings");

		ImGui::PopStyleVar(5);

		if (ImGui::BeginPopupModal("Settings", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_AlwaysAutoResize))
		{
			if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_NoTooltip))
			{
				if (ImGui::BeginTabItem("Unload"))
				{
					ImGui::Text("(!) Close any recording software before press Unload!");
					ImGui::Dummy({ 0,20 });
					if (ImGui::Button("Unload", { 160.f, 20.f })) Cheat::Unload();
					ImGui::SameLine();
					if (ImGui::Button("Close", { 160.5f, 20.f })) ImGui::CloseCurrentPopup();

					ImGui::EndTabItem();
				}
				ImGui::EndTabBar();
			}
			ImGui::EndPopup();
		}

		ImGui::Dummy({ 0, 7 });

		switch (iCurrentTab)
		{
		case 0:
		{
			ImGui::Spacing();
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 16, 6 });
			ImGui::BeginChild("##Weapons", { 0, 50 }, true);
			{
				ImGui::PushFont(pIcons);

				if (iCurrentCategory == 0) ActiveButton(); else NormalButton();
				if (ImGui::Button("A", { 0, 32 })) iCurrentCategory = 0;
				ImGui::PopStyleColor(4);
				ImGui::SameLine(105);

				if (iCurrentCategory == 1) ActiveButton(); else NormalButton();
				if (ImGui::Button("H", { 0, 32 })) iCurrentCategory = 1;
				ImGui::PopStyleColor(4);
				ImGui::SameLine(200);

				if (iCurrentCategory == 2) ActiveButton(); else NormalButton();
				if (ImGui::Button("c", { 0, 32 })) iCurrentCategory = 2;
				ImGui::PopStyleColor(4);
				ImGui::SameLine(325);

				if (iCurrentCategory == 3) ActiveButton(); else NormalButton();
				if (ImGui::Button("T", { 0, 32 })) iCurrentCategory = 3;
				ImGui::PopStyleColor(4);
				ImGui::SameLine(445);

				if (iCurrentCategory == 4) ActiveButton(); else NormalButton();
				if (ImGui::Button("Z", { 0, 32 })) iCurrentCategory = 4;
				ImGui::PopStyleColor(4);

				ImGui::PopFont();
				ImGui::PopStyleVar();
				ImGui::EndChild();
			}

			ImGui::BeginGroup();
			ImGui::BeginChild("##Aimbot", { 280, 147 }, true, ImGuiWindowFlags_MenuBar);
			{
				if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Aimbot"), ImGui::EndMenuBar();
				ImGui::Checkbox("Aimbot Range", &g_Config.g_Aimbot.bAimbot); ImGui::SameLine(202); ImGui::Button("Settings##Range", { 70, 0 });
				if (ImGui::BeginPopupContextItem(0, 0))
				{
					if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Aimbot Range Settings"), ImGui::EndMenuBar();
					ImGui::Checkbox("Render Range", &g_Config.g_Aimbot.bDrawRange); ImGui::SameLine(150); ImGui::PushItemWidth(70);
					ImGui::Combo("##RangeStyle", &g_Config.g_Aimbot.iRangeStyle, "Filled\0Outline\0");
					ImGui::Checkbox("Render Tracer", &g_Config.g_Aimbot.bDrawTracer); ImGui::SameLine(150);
					ImGui::SliderFloat("##OutlineThickness", &g_Config.g_Aimbot.fOutlineThickness, 1.0f, 5.0f, "%0.1f"); Tooltip("Thickness"); ImGui::PopItemWidth();
					ImGui::PushItemWidth(161);
					ImGui::ColorEdit4("Range", (float*)&g_Config.g_Aimbot.colorRange, ImGuiColorEditFlags_AlphaBar); ImGui::PopItemWidth();
					ImGui::EndPopup();
				}
				ImGui::Checkbox("Silent Aimbot", &g_Config.g_Aimbot.bSilent); ImGui::SameLine(202); ImGui::PushItemWidth(70.f);
				ImGui::SliderFloat("##Accuracy", &g_Config.g_Aimbot.fSilentAccuracy, 20.f, 100.f, "%.0f%%"); Tooltip("Silent Recoil"); ImGui::PopItemWidth();
				ImGui::Checkbox("Smooth Aimbot", &g_Config.g_Aimbot.bSmooth); ImGui::SameLine(202); ImGui::Button("Settings##Smooth", { 70, 0 });
				if (ImGui::BeginPopupContextItem(0, 0))
				{
					if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Smooth Aimbot Settings"), ImGui::EndMenuBar();
					ImGui::Checkbox("Aim On Fire", &g_Config.g_Aimbot.bSmoothIsFire);
					ImGui::Checkbox("Stop On Body", &g_Config.g_Aimbot.bStopOnBody);
					ImGui::Checkbox("Lock Y Axis", &g_Config.g_Aimbot.bSmoothLockY);
					ImGui::EndPopup();
				}
				ImGui::Checkbox("Pro Aimbot", &g_Config.g_Aimbot.bProAim);
				ImGui::Checkbox("Triggerbot", &g_Config.g_Aimbot.bTriggerbot); ImGui::SameLine(202); ImGui::Button("Settings##Trigger", { 70, 0 });
				if (ImGui::BeginPopupContextItem(0, 0))
				{
					if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Triggerbot Settings"), ImGui::EndMenuBar();
					ImGui::Checkbox("Delay", &g_Config.g_Aimbot.bTriggerDelay); ImGui::SameLine(150); ImGui::PushItemWidth(70);
					ImGui::DragInt("##TriggerDelay", &g_Config.g_Aimbot.iTriggerDelay, 1, 0, 500, "%d ms");
					if (!g_Config.g_Aimbot.bAimbot || !g_Config.g_Aimbot.bSilent)
					{
						ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
						ImGui::PushStyleVar(ImGuiStyleVar_Alpha, ImGui::GetStyle().Alpha * 0.5f);
					}
					ImGui::Checkbox("Sync with Silent", &g_Config.g_Aimbot.bTriggerSync); ImGui::SameLine();
					if (!g_Config.g_Aimbot.bAimbot || !g_Config.g_Aimbot.bSilent)
					{
						ImGui::PopItemFlag();
						ImGui::PopStyleVar();
						Tooltip("Enable Range and Silent to use this function!");
					}
					ImGui::EndPopup();
				}
				ImGui::EndChild();
			}
			ImGui::BeginChild("##Filters", { 280, 147 }, true, ImGuiWindowFlags_MenuBar);
			{
				if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Aimbot Filters"), ImGui::EndMenuBar();
				ImGui::Checkbox("Team Protect", &g_Config.g_Aimbot.bTeamProtect);
				ImGui::Checkbox("Lock Through Objects", &g_Config.g_Aimbot.bLockThroughObjects);
				ImGui::Checkbox("Ignore Max Distance", &g_Config.g_Aimbot.bIgnoreMaxDistance);
				ImGui::Checkbox("Ignore AFK", &g_Config.g_Aimbot.bIgnoreAFK);
				ImGui::Checkbox("Ignore Everything", &g_Config.g_Aimbot.bIgnoreEverything);
				ImGui::EndChild();
			}
			ImGui::EndGroup();
			ImGui::SameLine();
			ImGui::BeginGroup();
			ImGui::BeginChild("##Config", { 280, 101 }, true, ImGuiWindowFlags_MenuBar);
			{
				if (ImGui::BeginMenuBar()) ImGui::TextUnformatted(szCategory[pMenu->iCurrentCategory]), ImGui::EndMenuBar();
				for (auto i : mapWeapons)
				{
					if (i.second.iCategory != pMenu->iCurrentCategory)
						continue;

					ImGui::Checkbox(i.second.szName.c_str(), &g_Config.g_Aimbot.bAimbotEnabled[i.first]); ImGui::SameLine(202);
					ImGui::Button(("Config##" + std::to_string(i.first)).c_str(), { 70, 0 });
					if (ImGui::BeginPopupContextItem(0, 0))
					{
						if (ImGui::BeginMenuBar()) ImGui::Text("%s (%d) Configuration", i.second.szName.c_str(), i.first), ImGui::EndMenuBar();
						g_Config.g_Aimbot.bAimbot ? ImGui::TextUnformatted("Range") : ImGui::TextDisabled("Range"); ImGui::SameLine(120);
						ImGui::SliderInt("##Range", &g_Config.g_Aimbot.iAimbotConfig[i.first][RANGE], 1, 200, "%d px");
						if (ImGui::IsItemActive())
							g_Config.g_Aimbot.iRangeStyle ? ImGui::GetOverlayDrawList()->AddCircle({ pAimbot->vecCrosshair.x, pAimbot->vecCrosshair.y }, g_Config.g_Aimbot.iAimbotConfig[i.first][RANGE] * 1.5f, (ImColor)g_Config.g_Aimbot.colorRange, 64, g_Config.g_Aimbot.fOutlineThickness) :
							ImGui::GetOverlayDrawList()->AddCircleFilled({ pAimbot->vecCrosshair.x, pAimbot->vecCrosshair.y }, g_Config.g_Aimbot.iAimbotConfig[i.first][RANGE] * 1.5f, (ImColor)g_Config.g_Aimbot.colorRange, 64);
						g_Config.g_Aimbot.bSilent ? ImGui::TextUnformatted("Hitchance") : ImGui::TextDisabled("Hitchance"); ImGui::SameLine(120);
						ImGui::SliderInt("##Silent", &g_Config.g_Aimbot.iAimbotConfig[i.first][SILENT], 1, 100, "%d%%");
						g_Config.g_Aimbot.bSmooth ? ImGui::TextUnformatted("Smoothness") : ImGui::TextDisabled("Smoothness"); ImGui::SameLine(120);
						ImGui::SliderInt("##Smooth", &g_Config.g_Aimbot.iAimbotConfig[i.first][SMOOTH], 1, 100, "%d%%");
						ImGui::EndPopup();
					}
				}
				ImGui::EndChild();
			}
			ImGui::BeginChild("##Combat", { 280, 193 }, true, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoScrollbar);
			{
				static int iCombatTab{ 1 };
				if (ImGui::BeginMenuBar())
				{
					ImGui::TextUnformatted("Combat Assistance");
					ImGui::SameLine(194);
					if (iCombatTab == 1) ImGui::ArrowButtonDisabled("##CombatLeft", ImGuiDir_Left);
					else if (ImGui::ArrowButton("##CombatLeft", ImGuiDir_Left)) iCombatTab = 1;
					ImGui::SameLine(217); ImGui::TextUnformatted((std::to_string(iCombatTab) + "/2").c_str()); ImGui::SameLine(245);
					if (iCombatTab == 2) ImGui::ArrowButtonDisabled("##CombatRight", ImGuiDir_Right);
					else if (ImGui::ArrowButton("##CombatRight", ImGuiDir_Right)) iCombatTab = 2;
					ImGui::EndMenuBar();
				}
				switch (iCombatTab)
				{
				case 1:
				{
					ImGui::Checkbox("No Reload", &g_Config.g_Combat.bNoReload);
					ImGui::Checkbox("Allow C-BUG", &g_Config.g_Combat.bAllowCBug); ImGui::SameLine(202); ImGui::Button("Settings##AllowCBUG", { 70, 0 });
					if (ImGui::BeginPopupContextItem(0, 0))
					{
						if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Allow C-BUG Settings"), ImGui::EndMenuBar();
						ImGui::Checkbox("Disable Freeze", &g_Config.g_Combat.bCBugFreeze);
						ImGui::Checkbox("Disable Anim", &g_Config.g_Combat.bCBugAnim);
						ImGui::Checkbox("Disable GameText", &g_Config.g_Combat.bCBugText);
						ImGui::Checkbox("Disable Weapon Remove", &g_Config.g_Combat.bCBugWeapon);
						ImGui::EndPopup();
					}
					ImGui::Checkbox("Rapid Fire", &g_Config.g_Combat.bRapidFire); ImGui::SameLine(202);	ImGui::PushItemWidth(70); ImGui::SliderFloat("##RapidFire", &g_Config.g_Combat.fRapidFire, 1.0f, 10.0f, "%0.1f");	ImGui::PopItemWidth();
					ImGui::Checkbox("No Recoil", &g_Config.g_Combat.bNoRecoil);
					ImGui::Checkbox("Fast Crosshair", &g_Config.g_Combat.bFastCrosshair);
					ImGui::Checkbox("Weapon Switcher", &g_Config.g_Combat.bWeaponSwitcher); ImGui::SameLine(202); ImGui::Button("Settings##WeaponSwitcher", { 70, 0 });
					if (ImGui::BeginPopupContextItem(0, 0))
					{
						if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Weapon Switcher Settings"), ImGui::EndMenuBar();
						static int iComboWeapon = 0;
						ImGui::PushItemWidth(140); ImGui::Combo("##WeaponCombo", &iComboWeapon, szCategory, 5); ImGui::PopItemWidth(); ImGui::SameLine();
						ImGui::PushItemWidth(100); ImGui::Hotkey("##WeaponHotkey", &g_Config.g_Hotkeys.iWeaponSwitch[iComboWeapon]); ImGui::PopItemWidth();
						ImGui::Checkbox("Fast Switch", &g_Config.g_Combat.bFastSwitch);
						ImGui::EndPopup();
					}
					ImGui::Checkbox("Auto Scroll", &g_Config.g_Combat.bAutoScroll);
					break;
				}
				case 2:
				{
					ImGui::Checkbox("Auto C-Bug", &g_Config.g_Combat.bAutoCBug); ImGui::SameLine(202); ImGui::Button("Settings##AutoC-Bug", { 70, 0 });
					if (ImGui::BeginPopupContextItem(0, 0))
					{
						if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Auto C-BugSettings"), ImGui::EndMenuBar();
						ImGui::TextUnformatted("Bullet Delay"); ImGui::SameLine(150); ImGui::PushItemWidth(70);
						ImGui::DragInt("##BulletDelay", &g_Config.g_Combat.iCBugDelay[0], 1, 0, 100, "%d ms");
						ImGui::TextUnformatted("C Key Press Delay"); ImGui::SameLine(150); ImGui::PushItemWidth(70);
						ImGui::DragInt("##CKeyPressDelay", &g_Config.g_Combat.iCBugDelay[1], 1, 0, 100, "%d ms");
						ImGui::EndPopup();
					}
					break;
				}
				}
				ImGui::EndChild();
			}
			ImGui::EndGroup();
			break;
		}
		case 1:
		{
			ImGui::Spacing();
			ImGui::BeginChild("##Player", { 280, 352 }, true, ImGuiWindowFlags_MenuBar);
			{
				if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Player Assistance"), ImGui::EndMenuBar();
				ImGui::PushItemWidth(70);
				ImGui::Checkbox("Anti Stun", &g_Config.g_Player.bAntiStun); ImGui::SameLine(202); ImGui::SliderInt("##AntiStun", &g_Config.g_Player.iAntiStunChance, 1, 100);
				ImGui::Checkbox("Fast Rotation", &g_Config.g_Player.bFastRotation); ImGui::SameLine(202); ImGui::SliderInt("##FastRotation", &g_Config.g_Player.iFastRotation, 15, 100);
				ImGui::Checkbox("Fast Sprint", &g_Config.g_Player.bFastSprint); ImGui::SameLine(202); ImGui::SliderFloat("##FastSprint", &g_Config.g_Player.fFastSprint, 1.0f, 1.5f, "%0.1f");
				if (ImGui::Checkbox("Air Break", &g_Config.g_Player.bAirBreak))
					g_Config.g_Player.bMapRun = false;
				ImGui::SameLine(202); ImGui::SliderInt("##AirBreak", &g_Config.g_Player.iAirBreak, 1, 100);
				if (ImGui::Checkbox("Map Run", &g_Config.g_Player.bMapRun))
					g_Config.g_Player.bAirBreak = false;
				ImGui::SameLine(202); ImGui::SliderInt("##MapRun", &g_Config.g_Player.iMapRun, 1, 100);
				ImGui::Checkbox("Infinite Energy", &g_Config.g_Player.bInfiniteRun);
				ImGui::Checkbox("Infinite Oxygen", &g_Config.g_Player.bInfiniteOxygen);
				ImGui::Checkbox("Fast Respawn", &g_Config.g_Player.bFastRespawn);
				ImGui::Checkbox("No Fall", &g_Config.g_Player.bNoFall);
				ImGui::Checkbox("Mega Jump", &g_Config.g_Player.bMegaJump); ImGui::SameLine(202); ImGui::SliderFloat("##MegaJump", &g_Config.g_Player.fMegaJump, 1.0f, 5.0f, "%0.1f");
				ImGui::Checkbox("Stop On Exit Veh", &g_Config.g_Player.bStopOnExitVehicle); ImGui::SameLine(202); ImGui::DragInt("##StopOnExit", &g_Config.g_Player.iStopOnExitVehicle, 1, 500, 1500, "%d ms");
				ImGui::Checkbox("Auto Bike Spam", &g_Config.g_Player.bAutoBikeSpam); ImGui::SameLine(202); ImGui::Button("Settings##AutoBikeSpam", { 70, 0 });
				if (ImGui::BeginPopupContextItem(0, 0))
				{
					if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Auto Bike Spam Settings"), ImGui::EndMenuBar();
					ImGui::TextUnformatted("Hold Key"); ImGui::SameLine(120); ImGui::PushItemWidth(100); ImGui::Hotkey("##BikeHotkey", &g_Config.g_Hotkeys.iAutoBikeSpam);
					ImGui::Checkbox("Motorbike", &g_Config.g_Player.bMotorBikeSpam); ImGui::SameLine(120); ImGui::Hotkey("##MotorbikeHotkey", &g_Config.g_Hotkeys.iMotorBikeSpam); ImGui::PopItemWidth();
					ImGui::EndPopup();
				}
				ImGui::Checkbox("Change Skin", &g_Config.g_Player.bChangeSkin); ImGui::SameLine(202);
				ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, { 1, 0 }); ImGui::InputInt("##SkinID", &g_Config.g_Player.iSkinID); ImGui::PopStyleVar();
				ImGui::PopItemWidth();
				ImGui::EndChild();
			}
			ImGui::SameLine();
			ImGui::BeginChild("##Sync", { 280, 170 }, true, ImGuiWindowFlags_MenuBar);
			{
				if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Sync Modifications"), ImGui::EndMenuBar();
				ImGui::Checkbox("Upside Mode", &g_Config.g_Player.bUpsideMode);
				ImGui::Checkbox("Invert Walk", &g_Config.g_Player.bInvertWalk);
				ImGui::Checkbox("Shake Mode", &g_Config.g_Player.bShakeMode);
				ImGui::Checkbox("Invalid Aim Z", &g_Config.g_Player.bInvalidAimZ);
				ImGui::Checkbox("Invisible", &g_Config.g_Player.bInvisible);
				ImGui::PushItemWidth(70);
				ImGui::Checkbox("Fake Lag", &g_Config.g_Player.bFakeLag); ImGui::SameLine(202); ImGui::DragInt("##FakeLag", &g_Config.g_Player.iFakeLag, 1, 1, 500, "%d ms");
				ImGui::PopItemWidth();
				ImGui::EndChild();
			}
			break;
		}
		case 2:
		{
			ImGui::Spacing();
			ImGui::BeginGroup();
			ImGui::BeginChild("##PlayerESP", { 280, 193 }, true, ImGuiWindowFlags_MenuBar);
			{
				if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Player ESP"), ImGui::EndMenuBar();
				ImGui::Checkbox("ESP Name", &g_Config.g_Visuals.bNameTagsESP);
				ImGui::Checkbox("ESP Box", &g_Config.g_Visuals.bBoxESP); ImGui::SameLine(202);
				ImGui::PushItemWidth(50.f);
				ImGui::Combo("##RangeStyle", &g_Config.g_Visuals.iBoxStyle, "2D\0" "3D\0"); ImGui::PopItemWidth(); ImGui::SameLine(0.0f, 1.0f);
				ImGui::Checkbox("##BoxFilled", &g_Config.g_Visuals.bFilledBox); Tooltip("Filled");
				ImGui::Checkbox("ESP Chams", &g_Config.g_Visuals.bChamsESP);
				ImGui::Checkbox("ESP Snipeline", &g_Config.g_Visuals.bSnipelineESP); ImGui::SameLine(202);
				ImGui::PushItemWidth(70.f);
				ImGui::Combo("##SnipelineStyle", &g_Config.g_Visuals.iSnipelineStyle, "Above\0Down\0");
				ImGui::PopItemWidth();
				ImGui::Checkbox("ESP Bones", &g_Config.g_Visuals.bBoneESP);
				ImGui::Checkbox("ESP Weapon", &g_Config.g_Visuals.bWeaponESP);
				ImGui::Checkbox("ESP Distance", &g_Config.g_Visuals.bDistanceESP);
				ImGui::EndChild();
			}
			ImGui::BeginChild("##ESPSettings", { 280, 155 }, true, ImGuiWindowFlags_MenuBar);
			{
				if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("ESP Settings"), ImGui::EndMenuBar();
				ImGui::TextUnformatted("ESP Thickness"); ImGui::SameLine(202); ImGui::PushItemWidth(70.f);
				ImGui::SliderFloat("##Thickness", &g_Config.g_Visuals.fESPThickness, 1.0f, 3.0f, "%0.1f");
				ImGui::PopItemWidth();
				ImGui::Checkbox("Disable for Teammates", &g_Config.g_Visuals.bESPTeammates);
				ImGui::Checkbox("Use Custom Colors", &g_Config.g_Visuals.bESPCustomColors);
				ImGui::PushItemWidth(160.f);
				ImGui::ColorEdit4("Visible", (float*)&g_Config.g_Visuals.colorVisible, ImGuiColorEditFlags_AlphaBar);
				ImGui::ColorEdit4("Not Visible", (float*)&g_Config.g_Visuals.colorNotVisible, ImGuiColorEditFlags_AlphaBar);
				ImGui::PopItemWidth();
				ImGui::EndChild();
			}
			ImGui::EndGroup();
			ImGui::SameLine();
			ImGui::BeginGroup();
			ImGui::BeginChild("##VehicleESP", { 280, 170 }, true, ImGuiWindowFlags_MenuBar);
			{
				if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Vehicle ESP"), ImGui::EndMenuBar();
				ImGui::Checkbox("ESP Name ##Vehicle", &g_Config.g_Visuals.bVehicleNameTagsESP);
				ImGui::Checkbox("ESP Health", &g_Config.g_Visuals.bVehicleHPESP);
				ImGui::Checkbox("ESP Engine", &g_Config.g_Visuals.bVehicleEngineESP);
				ImGui::Checkbox("ESP Status", &g_Config.g_Visuals.bVehicleStatusESP);
				ImGui::Checkbox("ESP Distance", &g_Config.g_Visuals.bVehicleDistanceESP);
				ImGui::Checkbox("ESP Bounding Box", &g_Config.g_Visuals.bVehicleBoundingBoxESP);
				ImGui::EndChild();
			}
			ImGui::BeginChild("##Visuals", { 280, 178 }, true, ImGuiWindowFlags_MenuBar);
			{
				if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Visuals"), ImGui::EndMenuBar();
				ImGui::Checkbox("Aspect Ratio", &g_Config.g_Visuals.bAspectRatio); ImGui::SameLine(202); ImGui::PushItemWidth(70); ImGui::SliderFloat("##AspectRatio", &g_Config.g_Visuals.fAspectRatio, 0.5f, 2.0f, "%0.1f"); ImGui::PopItemWidth();
				ImGui::Checkbox("Damage Informer", &g_Config.g_Visuals.bDMGInformer); ImGui::SameLine(202); ImGui::Button("Settings##DMG", { 70, 0 });
				if (ImGui::BeginPopupContextItem(0, 0))
				{
					if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Damage Informer Settings"), ImGui::EndMenuBar();
					ImGui::TextUnformatted("Font Size"); ImGui::SameLine(150); ImGui::PushItemWidth(70);
					ImGui::SliderInt("##DMGFont", &g_Config.g_Visuals.iFontSize, 7, 20, "%d px");
					ImGui::TextUnformatted("Time on screen"); ImGui::SameLine(150); ImGui::PushItemWidth(70);
					ImGui::DragFloat("##DMGTick", &g_Config.g_Visuals.fDMGTick, 0.1f, 0.1f, 10.0f, "%.1f s");
					ImGui::PushItemWidth(161);
					ImGui::ColorEdit4("Text", (float*)&g_Config.g_Visuals.colorDMG, ImGuiColorEditFlags_AlphaBar);
					ImGui::PopItemWidth();
					ImGui::EndPopup();
				}
				ImGui::Checkbox("FPS Funcs", &g_Config.g_Visuals.bFPSFuncs); ImGui::SameLine(202);
				ImGui::Button("Settings##FPSFuncs", { 70, 0 });
				if (ImGui::BeginPopupContextItem(0, 0))
				{
					if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("FPS Funcs Settings"), ImGui::EndMenuBar();
					ImGui::PushItemWidth(40.f);
					ImGui::Checkbox("FPS Unlock", &g_Config.g_Visuals.bFPSUnlock);
					ImGui::Checkbox("FPS Boost", &g_Config.g_Visuals.bFPSBoost);
					ImGui::Checkbox("Fake FPS", &g_Config.g_Visuals.bFakeFPS); ImGui::SameLine(135);
					ImGui::InputInt("##MinFPS", &g_Config.g_Visuals.iMinFPS, 0); Tooltip("Min FPS"); ImGui::SameLine(177); ImGui::InputInt("##MaxFPS", &g_Config.g_Visuals.iMaxFPS, 0); Tooltip("Max FPS");
					if (g_Config.g_Visuals.iMinFPS > g_Config.g_Visuals.iMaxFPS)
						g_Config.g_Visuals.iMaxFPS = g_Config.g_Visuals.iMinFPS;
					ImGui::PopItemWidth();
					ImGui::End();
				}
				ImGui::Checkbox("Weather Changer", &g_Config.g_Visuals.bWeatherChanger); ImGui::SameLine(202); ImGui::Button("Settings##Weather", { 70, 0 });
				if (ImGui::BeginPopupContextItem(0, 0))
				{
					if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Weather Changer"), ImGui::EndMenuBar();
					ImGui::TextUnformatted("Weather"); ImGui::SameLine(100); ImGui::SameLine(150); ImGui::PushItemWidth(70); ImGui::SliderInt("##Weather", &g_Config.g_Visuals.iWeather, 0, 20);
					ImGui::Checkbox("Time Changer", &g_Config.g_Visuals.bTimeChanger); ImGui::SameLine(150); ImGui::SliderInt("##Time", &g_Config.g_Visuals.iTime, 0, 24); ImGui::PopItemWidth();
					ImGui::EndPopup();
				}
				ImGui::Checkbox("No Drugs Effect", &g_Config.g_Visuals.bNoDrugsEffect);
				ImGui::EndChild();
			}
			ImGui::EndGroup();
			break;
		}
		case 3:
		{
			ImGui::Spacing();
			ImGui::BeginGroup();
			ImGui::BeginChild("##Theme", { 280, 352 }, true, ImGuiWindowFlags_MenuBar);
			{
				if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Theme"), ImGui::EndMenuBar();
				if (ImGui::Button("Set Default Theme", { 259, 23 }))
					pMenu->Theme();

				for (int i = 0; i < ImGuiCol_COUNT; i++)
				{
					ImGui::PushID(i);
					ImGui::Text(ImGui::GetStyleColorName(i));
					ImGui::SameLine(176);
					ImGui::PushItemWidth(90);
					ImGui::ColorEdit4("##Color", (float*)&ImGui::GetStyle().Colors[i], ImGuiColorEditFlags_DisplayHex | ImGuiColorEditFlags_AlphaBar);
					ImGui::PopItemWidth();
					if (memcmp(&ImGui::GetStyle().Colors[i], &g_Config.g_Style.vecTheme[i], sizeof(ImVec4)) != 0)
						g_Config.g_Style.vecTheme[i] = ImGui::GetStyle().Colors[i];
					ImGui::PopID();
				}

				ImGui::EndChild();
				ImGui::EndGroup();
			}
			ImGui::SameLine();
			ImGui::BeginChild("##Styles", { 280, 352 }, true, ImGuiWindowFlags_MenuBar);
			{
				if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Styles"), ImGui::EndMenuBar();
				ImGui::TextUnformatted("Menu Colors"); ImGui::SameLine(177); ImGui::PushItemWidth(95);
				if (ImGui::Combo("##MenuColors", &g_Config.g_Style.iTheme, "Default\0Dark\0Light\0Classic\0Green\0"))
					Theme();

				ImGui::TextUnformatted("Checkbox Style"); ImGui::SameLine(177); ImGui::Combo("##CheckboxStyle", &g_Config.g_Style.iCheckbox, "Checkmark\0Filled\0");
				ImGui::PopItemWidth();
				ImGui::EndChild();
			}
			break;
		}
		case 4:
		{
			ImGui::Spacing();
			ImGui::BeginGroup();
			ImGui::BeginChild("##Damager", { 280, 194 }, true, ImGuiWindowFlags_MenuBar);
			{
				if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Damager"), ImGui::EndMenuBar();
				ImGui::PushItemWidth(70.f);
				ImGui::Checkbox("Damager", &g_Config.g_Developer.bDamager);
				ImGui::Checkbox("Delay", &g_Config.g_Developer.bDelay); ImGui::SameLine(202); ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, { 1, 0 }); ImGui::InputInt("##Delay", &g_Config.g_Developer.iDelay); ImGui::PopStyleVar();
				ImGui::Checkbox("Team Protect", &g_Config.g_Developer.bTeamProtect);
				ImGui::Checkbox("Send Bullet Data", &g_Config.g_Developer.bSendBulletData);
				ImGui::Checkbox("Teleport To Player", &g_Config.g_Developer.bTeleportToPlayer);
				ImGui::Checkbox("Custom Weapon", &g_Config.g_Developer.bCustomWeapon); ImGui::SameLine(202); ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, { 1, 0 }); ImGui::InputInt("##WeaponID", &g_Config.g_Developer.iWeaponID); ImGui::PopStyleVar();
				ImGui::Checkbox("Custom Damage", &g_Config.g_Developer.bCustomDamage); ImGui::SameLine(202); ImGui::InputFloat("##Damage", &g_Config.g_Developer.fDamage);
				ImGui::PopItemWidth();
				ImGui::EndChild();
			}

			ImGui::BeginChild("##Extra", { 280, 194 }, true, ImGuiWindowFlags_MenuBar);
			{
				if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Extra"), ImGui::EndMenuBar();

				ImGui::EndChild();
			}
			ImGui::EndGroup();

			ImGui::SameLine();

			ImGui::BeginChild("##Configs", { 280, 179 }, true, ImGuiWindowFlags_MenuBar);
			{
				if (ImGui::BeginMenuBar()) ImGui::TextUnformatted("Configs"), ImGui::EndMenuBar();
				ImGui::Columns(2, NULL, false);
				ImGui::SetColumnOffset(1, 170);
				ImGui::PushItemWidth(160);

				if (ImGui::Button("Reload configs", { 160, 25 }))
					pConfig->listConfigs();

				auto& vecConfigs = pConfig->getConfigs();
				static int iCurrentConfig = -1;

				if (static_cast<std::size_t>(iCurrentConfig) >= vecConfigs.size())
					iCurrentConfig = -1;

				static std::string szBuffer;

				if (ImGui::ListBox("", &iCurrentConfig, [](void* data, int idx, const char** out_text) {
					auto& vector = *static_cast<std::vector<std::string>*>(data);
					*out_text = vector[idx].c_str();
					return true;
					}, &vecConfigs, vecConfigs.size(), 5) && iCurrentConfig != -1)
					szBuffer = vecConfigs[iCurrentConfig];

					ImGui::PushID(0);
					if (ImGui::InputTextWithHint("", "Name", szBuffer.data(), szBuffer.capacity() + 1, ImGuiInputTextFlags_EnterReturnsTrue))
					{
						if (iCurrentConfig != -1)
							pConfig->Rename(iCurrentConfig, szBuffer.c_str());
					}
					ImGui::PopID();
					ImGui::NextColumn();

					ImGui::PushItemWidth(100);

					if (ImGui::Button("Create", { 95, 25 }))
						pConfig->Add(szBuffer.c_str());

					if (ImGui::Button("Reset", { 95, 25 }))
						ImGui::OpenPopup("Config to reset");

					if (ImGui::BeginPopup("Config to reset"))
					{
						static const char* szConfigs[]{ "Whole", "Aimbot", "Combat", "Player", "Visuals", "Style", "Hotkeys" };
						for (int i = 0; i < IM_ARRAYSIZE(szConfigs); i++)
						{
							if (i == 1) ImGui::Separator();
							if (ImGui::Selectable(szConfigs[i]))
							{
								switch (i)
								{
								case 0: pConfig->Reset(); Theme(); break;
								case 1: g_Config.g_Aimbot = { }; break;
								case 2: g_Config.g_Combat = { }; break;
								case 3: g_Config.g_Player = { }; break;
								case 4: g_Config.g_Visuals = { }; break;
								case 5: g_Config.g_Style = { }; Theme();  break;
								case 6: g_Config.g_Hotkeys = { }; break;
								}
							}
						}
						ImGui::EndPopup();
					}
					if (iCurrentConfig != -1)
					{
						ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 2);
						if (ImGui::Button("Load", { 95, 25 }))
						{
							pConfig->Load(iCurrentConfig);
							for (int i = 0; i < ImGuiCol_COUNT; i++)
								ImGui::GetStyle().Colors[i] = g_Config.g_Style.vecTheme[i];
						}
						if (ImGui::Button("Save", { 95, 25 }))
							pConfig->Save(iCurrentConfig);
						if (ImGui::Button("Delete", { 95, 25 }))
						{
							pConfig->Remove(iCurrentConfig);
							iCurrentConfig = -1;
							szBuffer.clear();
						}
					}
					ImGui::Columns(1);
					ImGui::EndChild();
			}
			break;
		}
		}

		ImGui::End();
	}

}
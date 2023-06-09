#include "main.h"

CPed* Player::pPedSelf;
bool Player::bExitVehicle = false;
ULONGLONG Player::dwExitTick = 0;

void Player::Update()
{
	pPedSelf = FindPlayerPed();
	if (!pPedSelf->IsAlive())
		return;

	AirBreak();
	AntiStun();
	FastRotation();
	FastSprint();
	InfiniteRun();
	InfiniteOxygen();
	NoFall();
	MegaJump();
	ChangeSkin();
	FastRespawn();
	StopOnExitVeh();
}

void Player::AirBreak()
{
	if (g_Config.g_Player.bAirBreak || g_Config.g_Player.bMapRun)
	{
		float fCameraRotation = *(float*)0xB6F178;
		float fSpeed = g_Config.g_Player.bAirBreak ? g_Config.g_Player.iAirBreak / 10.f : g_Config.g_Player.iMapRun / 10.f;
		CVector* nVec = &pPedSelf->m_matrix->pos;
		pPedSelf->m_fCurrentRotation = pPedSelf->m_fAimingRotation = -fCameraRotation;
		pPedSelf->m_vecMoveSpeed.z = 0.f;

		CVehicle* pVehicle = FindPlayerVehicle(-1, false);
		if (pVehicle)
		{
			nVec = &pVehicle->m_matrix->pos;
			float fDiff = Utils::vecLength(pVehicle->m_matrix->pos - *nVec);
			pVehicle->m_matrix->SetRotateZOnly(-fCameraRotation);
			pVehicle->m_matrix->pos.x = nVec->x - sinf(fCameraRotation) * fDiff;
			pVehicle->m_matrix->pos.y = nVec->y - cosf(fCameraRotation) * fDiff;
			pVehicle->m_vecMoveSpeed.x = pVehicle->m_vecMoveSpeed.y = pVehicle->m_vecMoveSpeed.z = 0.f;
		}
		else if (g_Config.g_Player.bAirBreak)
			pPedSelf->m_nPedFlags.bIsStanding = pPedSelf->m_nPedFlags.bWasStanding = pPedSelf->m_nPedFlags.bStayInSamePlace = true;
		else pPedSelf->m_nPedFlags.bIsStanding = true;

		if (isKeyDown('W'))
			nVec->x += sinf(fCameraRotation) * fSpeed, nVec->y += cosf(fCameraRotation) * fSpeed;
		if (isKeyDown('S'))
			nVec->x -= sinf(fCameraRotation) * fSpeed, nVec->y -= cosf(fCameraRotation) * fSpeed;
		if (isKeyDown('D'))
			nVec->x += cosf(fCameraRotation) * fSpeed, nVec->y -= sinf(fCameraRotation) * fSpeed;
		if (isKeyDown('A'))
			nVec->x -= cosf(fCameraRotation) * fSpeed, nVec->y += sinf(fCameraRotation) * fSpeed;

		if (g_Config.g_Player.bAirBreak)
		{
			if (isKeyDown(VK_SPACE))
				nVec->z += fSpeed;
			if (isKeyDown(VK_CONTROL))
				nVec->z -= fSpeed;
		}

		if (g_Config.g_Player.bMapRun)
		{
			CVector vecTarget = pPedSelf->GetPosition();
			float fPosZ = CWorld::FindGroundZForCoord(vecTarget.x, vecTarget.y) + 1.0f;

			CColPoint pCollision;
			CEntity* pCollisionEntity = NULL;
			bool bCollision = CWorld::ProcessLineOfSight(*nVec, vecTarget, pCollision, pCollisionEntity, 1, 0, 0, 1, 1, 0, 0, 0);
			if (bCollision)
				fPosZ = pCollision.m_vecPoint.z + 1.0f;

			float fCheckZ = CWorld::FindGroundZForCoord(vecTarget.x, vecTarget.y);
			if (fPosZ < fCheckZ)
				fPosZ = fCheckZ + 1.0f;

			float fWaterLevel;
			if (((bool(__cdecl*)(float, float, float, float*, bool, CVector*))0x6EB690)(vecTarget.x, vecTarget.y, vecTarget.z, &fWaterLevel, 1, new CVector()))
			{
				if (fPosZ < fWaterLevel)
					fPosZ = fWaterLevel + 1.0f;
			}
			nVec->z = fPosZ;
		}
	}
}

void Player::AntiStun()
{
	if (g_Config.g_Player.bAntiStun && rand() % 100 < g_Config.g_Player.iAntiStunChance)
		pPedSelf->m_nPedFlags.bUpperBodyDamageAnimsOnly = true;
	else pPedSelf->m_nPedFlags.bUpperBodyDamageAnimsOnly = false;
}

void Player::FastRotation()
{
	static bool bFastRotation = false;
	if (g_Config.g_Player.bFastRotation)
	{
		pPedSelf->m_fHeadingChangeRate = (float)g_Config.g_Player.iFastRotation;
		bFastRotation = true;
	}
	else if (bFastRotation)
	{
		pPedSelf->RestoreHeadingRate();
		bFastRotation = false;
	}
}

void Player::FastSprint()
{
	if (!g_Config.g_Player.bFastSprint)
		return;

	plugin::Command<plugin::Commands::SET_CHAR_ANIM_SPEED>(pPedSelf, "WOMAN_RUN", g_Config.g_Player.fFastSprint);
	plugin::Command<plugin::Commands::SET_CHAR_ANIM_SPEED>(pPedSelf, "WOMAN_RUNBUSY", g_Config.g_Player.fFastSprint);
	plugin::Command<plugin::Commands::SET_CHAR_ANIM_SPEED>(pPedSelf, "WOMAN_RUNPANIC", g_Config.g_Player.fFastSprint);
	plugin::Command<plugin::Commands::SET_CHAR_ANIM_SPEED>(pPedSelf, "WOMAN_RUNSEXY", g_Config.g_Player.fFastSprint);
	plugin::Command<plugin::Commands::SET_CHAR_ANIM_SPEED>(pPedSelf, "SPRINT_CIVI", g_Config.g_Player.fFastSprint);
	plugin::Command<plugin::Commands::SET_CHAR_ANIM_SPEED>(pPedSelf, "SPRINT_PANIC", g_Config.g_Player.fFastSprint);
	plugin::Command<plugin::Commands::SET_CHAR_ANIM_SPEED>(pPedSelf, "SWAT_RUN", g_Config.g_Player.fFastSprint);
	plugin::Command<plugin::Commands::SET_CHAR_ANIM_SPEED>(pPedSelf, "WOMAN_RUN", g_Config.g_Player.fFastSprint);
	plugin::Command<plugin::Commands::SET_CHAR_ANIM_SPEED>(pPedSelf, "WOMAN_RUNBUSY", g_Config.g_Player.fFastSprint);
	plugin::Command<plugin::Commands::SET_CHAR_ANIM_SPEED>(pPedSelf, "WOMAN_RUNPANIC", g_Config.g_Player.fFastSprint);
	plugin::Command<plugin::Commands::SET_CHAR_ANIM_SPEED>(pPedSelf, "WOMAN_RUNSEXY", g_Config.g_Player.fFastSprint);
	plugin::Command<plugin::Commands::SET_CHAR_ANIM_SPEED>(pPedSelf, "FATSPRINT", g_Config.g_Player.fFastSprint);
}

void Player::InfiniteRun()
{
	if (g_Config.g_Player.bInfiniteRun && pPedSelf->m_pPlayerData->m_fTimeCanRun < 100.f)
		FindPlayerPed()->ResetSprintEnergy();
}

void Player::InfiniteOxygen()
{
	if (g_Config.g_Player.bInfiniteOxygen && pPedSelf->m_pPlayerData->m_fBreath < 100.f)
		FindPlayerPed()->ResetPlayerBreath();
}

void Player::NoFall()
{
	if (!g_Config.g_Player.bNoFall)
		return;

	bool bOutResult = false; CEntity* pOutEntity;
	if (Utils::isPlayingAnimation(pPedSelf, "FALL_FALL") && pPedSelf->GetPosition().z - CWorld::FindGroundZFor3DCoord(pPedSelf->GetPosition().x, pPedSelf->GetPosition().y, pPedSelf->GetPosition().z, &bOutResult, &pOutEntity) < 1.5f)
	{
		Utils::DisembarkInstantly();
		pPedSelf->m_vecMoveSpeed.x = pPedSelf->m_vecMoveSpeed.y = pPedSelf->m_vecMoveSpeed.z = 0.f;
	}
}

void Player::MegaJump()
{
	static bool bMegaJump = false;
	if (g_Config.g_Player.bMegaJump)
	{
		pSecure->Write(0x8703C0, 8.5f * g_Config.g_Player.fMegaJump);
		bMegaJump = true;
	}
	else if (bMegaJump)
	{
		*(float*)0x8703C0 = 8.5f;
		bMegaJump = false;
	}
}

void Player::ChangeSkin()
{
	int iSkin = g_Config.g_Player.iSkinID;
	if (g_Config.g_Player.bChangeSkin && iSkin >= 0 && iSkin <= 311 && iSkin != 74 && pPedSelf->m_nModelIndex != iSkin)
	{
		CStreaming::RequestModel(iSkin, 0);
		CStreaming::LoadAllRequestedModels(false);
		pPedSelf->SetModelIndex(iSkin);
	}
}

void Player::FastRespawn()
{
	if (g_Config.g_Player.bFastRespawn && pPedSelf->m_fHealth == 0)
		pPedSelf->m_fHealth = 99;
}

void Player::StopOnExitVeh()
{
	if (g_Config.g_Player.bStopOnExitVehicle && bExitVehicle)
	{
		if (GetTickCount64() - dwExitTick > (ULONGLONG)g_Config.g_Player.iStopOnExitVehicle)
		{
			bExitVehicle = false;
			Utils::DisembarkInstantly();
			dwExitTick = GetTickCount64();
		}
	}
}

void Player::BikeSpam()
{
	if (g_Config.g_Player.bAutoBikeSpam && FindPlayerVehicle(-1, false))
	{
		int16_t* i16KeyState = (int16_t*)0xB73458;
		if (isKeyDown(g_Config.g_Hotkeys.iAutoBikeSpam) && reinterpret_cast<CVehicleModelInfo*>(CModelInfo::ms_modelInfoPtrs[FindPlayerVehicle(-1, false)->m_nModelIndex])->m_nVehicleType == VEHICLE_BMX)
		{
			if (i16KeyState[BUTTON_CROSS] == 0)
				pKeyHook->g_GameKeyState[BUTTON_CROSS] = { 0xFF, true };
			else pKeyHook->g_GameKeyState[BUTTON_CROSS] = { 0x0, true };
		}
		if (g_Config.g_Player.bMotorBikeSpam && isKeyDown(g_Config.g_Hotkeys.iMotorBikeSpam) && reinterpret_cast<CVehicleModelInfo*>(CModelInfo::ms_modelInfoPtrs[FindPlayerVehicle(-1, false)->m_nModelIndex])->m_nVehicleType == VEHICLE_BIKE)
		{
			if (i16KeyState[BUTTON_LEFT_STICK_Y] == 0)
				pKeyHook->g_GameKeyState[BUTTON_LEFT_STICK_Y] = { -0x80, true };
			else pKeyHook->g_GameKeyState[BUTTON_LEFT_STICK_Y] = { 0x0, true };
		}
	}
}
/*
	Copyright 2016 sub1to

	This file is part of subVersion GTA:O SC External Hack.

    subVersion GTA:O SC External Hack is free software: you can redistribute
	it and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation, either version 3 of the
	License, or (at your option) any later version.

    subVersion GTA:O SC External Hack is distributed in the hope that it
	will be useful, but WITHOUT ANY WARRANTY; without even the implied
	warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
	the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with subVersion GTA:O SC External Hack.  If not, see <http://www.gnu.org/licenses/>.
*/

#define __SC_VERSION__
//#define __STEAM_VERSION__

#ifndef STDAFX_H
#define STDAFX_H

#include <windows.h>
#include <windowsx.h>
//#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <psapi.h>

#include <Dwmapi.h>
#pragma comment(lib,"Dwmapi.lib")

#include "d3d9/d3d9.h"
#include "d3d9/d3dx9.h"
#pragma comment(lib,"d3d9/d3dx9.lib")
#pragma comment(lib,"d3d9/d3d9.lib")

#include "resource.h"

#include "vector.h"
#include "memManager.h"
#include "D3D9Render.h"
#include "settings.h"
#include "entity.h"
#include "hack.h"


//Addresses from GTAV.exe module
#ifdef __SC_VERSION__
#define ADDRESS_WORLD					0x2303788		//42
#define ADDRESS_WAYPOINT				0x1F59BB0		//wtb a (mini)map struct
#define ADDRESS_AMMO					0x0F5BC65		//Ammo dec code; 41 2B D1 E8; 90 90 90 E8
#define ADDRESS_MAGAZINE				0x0F5BC20		//Magazine dec code; 41 2B C9 3B C8 0F; 90 90 90 3B C8 0F
#endif
#ifdef __STEAM_VERSION__
#define ADDRESS_WORLD					0x2307738		//42
#define ADDRESS_WAYPOINT				0x1F5DE50		//wtb a (mini)map struct
#define ADDRESS_AMMO					0x0F5C9E1		//Ammo dec code; 41 2B D1 E8; 90 90 90 E8
#define ADDRESS_MAGAZINE				0x0F5C99C		//Magazine dec code; 41 2B C9 3B C8 0F; 90 90 90 3B C8 0F
#endif

//offset from WORLD
#define OFFSET_PLAYER					0x08			//playerbase

//entity offsets
#define OFFSET_ENTITY_POSBASE			0x30			//base of a structure that contains entity coords
#define OFFSET_ENTITY_POSBASE_POS		0x50			//vector3
#define OFFSET_ENTITY_POS				0x90			//vector3
#define OFFSET_ENTITY_HEALTH			0x280			//entity health (except for vehicles); float cur, float max
#define OFFSET_ENTITY_HEALTH_MAX		0x2A0			//they moved this away from curHealth in 1.36 :(
#define OFFSET_ENTITY_ATTACKER			0x2A8			//base to a list of the last 3 entities that attacked the current entity
#define OFFSET_ENTITY_GOD				0x189			//godmode; on = 1, off = 0; byte

//player (entity) offsets
#define OFFSET_PLAYER_ARMOR						0x14A0			//armour
#define OFFSET_PLAYER_INFO						0x10A8			//playerInfo struct
#define OFFSET_PLAYER_INFO_WANTED_CAN_CHANGE	0x71C			//fWantedCanChange
#define OFFSET_PLAYER_INFO_WANTED				0x798			//wanted level; DWORD
#define	OFFSET_PLAYER_INFO_RUN_SPD				0xE8			//run speed; def 1; float
#define OFFSET_PLAYER_INFO_SWIM_SPD				0xE4			//swim speed; def 1; float
#define OFFSET_PLAYER_INFO_FRAMEFLAGS			0x190			//frame flags; DWORD
#define OFFSET_PLAYER_VEHICLE					0x14E0			//ptr to last used vehicle
#define OFFSET_PLAYER_NAME						0x7C
#define OFFSET_PLAYER_RAGDOLL					0x1098			//byte; CPed.noRagdoll: 0x20 = off; 0x00/0x01 = on
#define OFFSET_PLAYER_SEATBELT					0x13DC			//byte; CPed.seatBelt: 0xC8 = off; 0xC9 = on
#define OFFSET_PLAYER_INVEHICLE					0x145B

//vehicle offsets
#define OFFSET_VEHICLE_HEALTH						0x82C			//vehicle health; 0.f-1000.f
#define OFFSET_VEHICLE_GRAVITY						0xB4C			//fGravity
#define OFFSET_VEHICLE_BULLETPROOF_TIRES			0x85B			//btBulletproofTires;  (btBulletproofTires & 0x20) ? true : false
#define OFFSET_VEHICLE_HANDLING						0x850
#define OFFSET_VEHICLE_HANDLING_ACCELERATION		0x4C
#define OFFSET_VEHICLE_HANDLING_BRAKEFORCE			0x6C
#define OFFSET_VEHICLE_HANDLING_TRACTION_CURVE_MIN	0x90			//fTractionCurveMin
#define OFFSET_VEHICLE_HANDLING_DEFORM_MULTIPLIER	0xF8			//fDeformationDamageMult
#define OFFSET_VEHICLE_HANDLING_UPSHIFT				0x58
#define OFFSET_VEHICLE_HANDLING_SUSPENSION_FORCE	0xBC			//fSuspensionForce 

//weapon offsets
#define OFFSET_WEAPON_MANAGER			0x10B8			//from playerbase
#define OFFSET_WEAPON_CURRENT			0x20			//from weapon manager
#define OFFSET_WEAPON_AMMOINFO			0x48			//from weaponbase
#define OFFSET_WEAPON_AMMOINFO_MAX		0x28			//ammoinfo
#define OFFSET_WEAPON_AMMOINFO_CUR_1	0x08			//ptr lvl 1, ptr 1
#define OFFSET_WEAPON_AMMOINFO_CUR_2	0x00			//ptr tr lvl 2, ptr 1
#define OFFSET_WEAPON_AMMOINFO_CURAMMO	0x18			//offset to cur ammo
#define OFFSET_WEAPON_AMMOINFO_TYPE		0x0C			//offset to projectile type?
#define OFFSET_WEAPON_SPREAD			0x5C			//float set to 0
#define OFFSET_WEAPON_BULLET_DMG		0x98			//float times 10 (so when 0, it will stay 0)
#define OFFSET_WEAPON_RELOAD_MULTIPLIER	0x114			//float times 10
#define OFFSET_WEAPON_RECOIL			0x2A4			//float set to 0
#define OFFSET_WEAPON_MODEL_HASH		0x14
#define OFFSET_WEAPON_NAME_HASH			0x10
#define OFFSET_WEAPON_RELOAD_VEHICLE	0x110
#define OFFSET_WEAPON_RANGE				0x25C
#define OFFSET_WEAPON_SPINUP			0x124
#define OFFSET_WEAPON_SPIN				0x128
#define OFFSET_WEAPON_BULLET_BATCH		0x100			//dwBulletInBatch
#define OFFSET_WEAPON_MUZZLE_VELOCITY	0xFC			//fMuzzleVelocity
#define OFFSET_WEAPON_BATCH_SPREAD		0x104			//fBatchSpread


#define OFFSET_ATTACKER_DISTANCE		0x18			//changed to 0x18, from 0x10


//feature indexing
#define FEATURE_P_GOD				0x00
#define FEATURE_P_NEVERWANTED		0x01
#define FEATURE_P_ANTINPC			0x02
#define FEATURE_V_GOD				0x03
#define FEATURE_W_SPREAD			0x04
#define FEATURE_W_RECOIL			0x05
#define FEATURE_W_RELOAD			0x06
#define FEATURE_W_DAMAGE			0x07
#define FEATURE_W_AMMO				0x08
#define FEATURE_W_RANGE				0x09
#define FEATURE_W_SPINUP			0x0A
#define FEATURE_P_RUNSPD			0x0B
#define FEATURE_P_SWIMSPD			0x0C
#define FEATURE_P_TRUEGOD			0x0D
#define FEATURE_P_SUPERJUMP			0x0E
#define FEATURE_P_EXPLOSIVEMELEE	0x0F
#define FEATURE_W_EXPLOSIVEAMMO		0x10
#define FEATURE_W_FIREAMMO			0x11
#define FEATURE_V_TRUEGOD			0x12
#define FEATURE_P_NORAGDOLL			0x13
#define FEATURE_V_SEATBELT			0x14
#define FEATURE_W_NORELOAD			0x15
#define FEATURE_V_ACCELERATION		0x16
#define FEATURE_V_BRAKEFORCE		0x17
#define FEATURE_V_TRACTION			0x18
#define FEATURE_V_GRAVITY			0x19
#define FEATURE_V_BULLETPROOFTIRES	0x1A
#define FEATURE_P_WANTED			0x1B
#define FEATURE_W_BULLET_BATCH		0x1C
#define FEATURE_W_MUZZLE_VELOCITY	0x1D
#define FEATURE_V_DEFORMATION		0x1E
#define FEATURE_V_UPSHIFT			0x1F
#define FEATURE_W_BATCH_SPREAD		0x20
#define FEATURE_V_SUSPENSION_FORCE	0x21


void		killProgram	();
std::string	vkToStr	(int vk);

extern HWND		g_hWnd;
extern int		g_iFeature[MAX_MENU_FEATURES];

#endif

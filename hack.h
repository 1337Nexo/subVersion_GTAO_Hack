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

#pragma once
#ifndef HACK_H
#define HACK_H

class trainer
{
	public:
		clock_t		m_keyTmr;

						trainer();
						~trainer();
		bool			checkKeyState(int key);
		virtual void	checkKeys();
};

class hack : public trainer
{
	public:
		v2		m_v2Waypoint;
		player	m_player;
		vehicle m_vehicle;
		weapon	m_weapon;

		HMODULE	m_hModule;

				hack();
				~hack();
		void	checkKeys();
		bool	initPointers();
		void	teleport(v3 v);
		bool	teleportWaypoint();
		void	restoreHealth();
		void	restoreVehicleHealth();
		void	notWanted();
		void	killNpc();
		void	fillAmmo();
		void	noSpread(feat* feature);
		void	noRecoil(feat* feature);
		void	quickReload(feat* feature);
		void	bulletDamage(feat* feature);
		void	weaponRange(feat* feature);
		void	weaponSpin(feat* feature);
		void	runSpeed(feat* feature);
		void	swimSpeed(feat* feature);
		void	godMode(feat* feature);
		void	frameFlags(feat* featSuperJump, feat* featExplosiveMelee, feat* featFireAmmo, feat* featExplosiveAmmo);
		void	vehicleGod(feat* feature);
		void	infAmmo(feat* feature);
		void	noReload(feat* feature);
		void	seatbelt(feat* feature);
		void	noRagdoll(feat* feature);
		void	vehicleAccel(feat* feature);
		void	vehicleBrake(feat* feature);
		void	neverWanted(feat* feature);
		void	vehicleTraction(feat* feature);
		void	vehicleGravity(feat* feature);
		void	vehicleBulletproofTires(feat* feature);
		void	wanted(feat* feature);
		void	bulletBatch(feat* feature);
		void	muzzleVelocity(feat* feature);
		void	vehicleDeformation(feat* feature);
		void	vehicleUpShift(feat* feature);

	private:
		DWORD_PTR	m_dwpWorldBase,
					m_dwpPlayerBase,
					m_dwpVehicleBase,
					m_dwpAttackerBase,
					m_dwpWeaponManager,
					m_dwpWeaponCur,
					m_dwpAmmoInfo;

		void	getWaypoint();
};

extern hack*		g_pHack;

#endif
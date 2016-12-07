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
#ifndef ENTITY_H
#define ENTITY_H

struct health
{
	float cur, max;
};

class entity
{
	public:
		health	m_hp;
		v3		m_pos;
		BYTE	m_btGod;

						entity();
						~entity();
		virtual void	getPos();
		virtual void	setPos(v3 dest);
		virtual void	getHealth();
		virtual void	setHealth(float hp);
		virtual void	getGod();
		virtual void	setGod(BYTE value);

		DWORD_PTR	m_dwpBase,
					m_dwpPosBase;
};

class player : public entity
{
	public:
		float	m_flArmor,
				m_flRunSpd,
				m_flSwimSpd,
				m_flWantedCanChange;
		DWORD	m_dwWanted,
				m_dwFrameFlags;
		BYTE	m_btRagdoll,
				m_btSeatbelt;
		bool	m_bIsInVehicle;

						player();
						~player();
		virtual	void	getHealth();
		virtual	void	setHealth(float hp, float armor);
				void	getWanted();
				void	setWanted(DWORD stars);
				void	getWantedCanChange();
				void	setWantedCanChange(float value);
				void	getInVehicle();
				void	getRunSpeed();
				void	setRunSpeed(float value);
				void	getSwimSpeed();
				void	setSwimSpeed(float value);
				void	getFrameFlags();
				void	setFrameFlags(DWORD value);
				void	getRagdoll();
				void	setRagdoll(BYTE value);
				void	getSeatbelt();
				void	setSeatbelt(BYTE value);

		DWORD_PTR	m_dwpPlayerInfo;
};

class vehicle : public entity
{
	public:
		health	m_hpVehicle;
		float	m_fGravity;
		BYTE	m_btBulletproofTires;

		struct vehicleHandling
		{
			DWORD_PTR	m_dwpHandling = 0;
			float		m_fAcceleration,
						m_fBrakeForce,
						m_fTractionCurveMin;
		};

		vehicleHandling	m_handlingRestore,
						m_handlingCur;

				vehicle();
				~vehicle();
		void	getHealth();
		void	setHealth(float hp);
		bool	loadHandling();
		void	restoreHandling();
		void	getAcceleration();
		void	setAcceleration(float value);
		void	getBrakeForce();
		void	setBrakeForce(float value);
		void	getTractionCurveMin();
		void	setTractionCurveMin(float value);
		void	getGravity();
		void	setGravity(float value);
		void	getBulletproofTires();
		void	setBulletproofTires(BYTE value);
};

class weapon
{
	public:
		DWORD		m_dwCurAmmo,
					m_dwMaxAmmo,
					m_dwHash;		//name hash
		struct weaponData
		{
			DWORD		m_dwHash = 0,
						m_dwBulletBatch;
			DWORD_PTR	m_dwpWeapon	= 0;
			float		m_fSpread,		
						m_fRecoil,
						m_fDamage,
						m_fReload,
						m_fReloadVeh,
						m_fRange,
						m_fSpinUp,
						m_fSpin,
						m_fMuzzleVelocity;
		};

		weaponData	m_weapDataRestore,//the original values will be stored here.
					m_weapDataCur;
				
				weapon();
				~weapon();
		bool	loadWeapon();
		void	restoreWeapon();
		void	getReloadSpeed();
		void	setReloadSpeed(float value);
		void	getReloadVehicle();
		void	setReloadVehicle(float value);
		void	getBulletDamage();
		void	setBulletDamage(float value);
		void	getRecoil();
		void	setRecoil(float value);
		void	getSpread();
		void	setSpread(float value);
		void	getRange();
		void	setRange(float value);
		void	getSpinUp();
		void	setSpinUp(float value);
		void	getSpin();
		void	setSpin(float value);
		void	getHash();
		bool	findAmmoBase();
		void	getCurAmmo();
		void	setCurAmmo(DWORD ammo);
		void	getMaxAmmo();
		void	getBulletBatch();
		void	setBulletBatch(DWORD value);
		void	getMuzzleVelocity();
		void	setMuzzleVelocity(float value);

		DWORD_PTR	m_dwpAmmoInfo,
					m_dwpCurAmmoBase;
};

#endif
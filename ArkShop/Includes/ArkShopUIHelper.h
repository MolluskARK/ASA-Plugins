/*
 * Public API for ArkShopUI
 * Copyright (C) Lethal Plugins - All Rights Reserved
 * Unauthorized copying/distribution of these files, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Lethal <www.lethalplugins.com>, April 2024
 */
#pragma once

#include <API/ARK/Ark.h>

#ifdef ArkShopUI_EXPORTS
#define ARK_API __declspec(dllexport)
#else
#define ARK_API
#endif

namespace ArkShopUI
{
	inline ARK_API bool RequestUI(AShooterPlayerController* player_controller)
	{
		using T = bool (*) (AShooterPlayerController*);

		HMODULE hmodule = GetModuleHandleA("ArkShopUI.dll");
		if (!hmodule)
			return false;

		T addr = (T)GetProcAddress(hmodule, "RequestUI");

		return addr(player_controller);
	}

	inline ARK_API bool CanUseMod(int platform)
	{
		using T = bool (*) (int);

		HMODULE hmodule = GetModuleHandleA("ArkShopUI.dll");
		if (!hmodule)
			return false;

		T addr = (T)GetProcAddress(hmodule, "CanUseMod");

		return addr(platform);
	}

	inline ARK_API bool Reload()
	{
		using T = bool (*) ();

		HMODULE hmodule = GetModuleHandleA("ArkShopUI.dll");
		if (!hmodule)
			return false;

		T addr = (T)GetProcAddress(hmodule, "Reload");

		return addr();
	}

	inline ARK_API bool UpdatePoints(const FString& eos_id, int points)
	{
		using T = bool (*) (const FString&, int);

		HMODULE hmodule = GetModuleHandleA("ArkShopUI.dll");
		if (!hmodule)
			return false;

		T addr = (T)GetProcAddress(hmodule, "UpdatePoints");

		return addr(eos_id, points);
	}

	inline ARK_API bool PlayerKits(const FString& eos_id, FString kitdata)
	{
		using T = bool (*) (const FString&, FString);

		HMODULE hmodule = GetModuleHandleA("ArkShopUI.dll");
		if (!hmodule)
			return false;

		T addr = (T)GetProcAddress(hmodule, "PlayerKits");

		return addr(eos_id, kitdata);
	}
}
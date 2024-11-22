public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
    static weapon, ammo;
    #if defined _YSF_INCLUDED
        GetPlayerWeaponData(playerid, GetWeaponSlot(weaponid), weapon, ammo);
    #else
        for(new i = 0; i < 10; i++)
        {
            GetPlayerWeaponData(playerid, i, weapon, ammo);
            if(weapon == weaponid) break;
        }
    #endif
    if(ammo <= 1) 
    {
        GivePlayerWeapon(playerid, weaponid, 1);
        SetPlayerArmedWeapon(playerid, 0);
        return 0;
    }
    return 1;
}

#if defined _ALS_OnPlayerWeaponShot
    #undef OnPlayerWeaponShot
#else
    #define _ALS_OnPlayerWeaponShot
#endif
#if defined HOOK_OnPlayerWeaponShot
    forward HOOK_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ); 
#endif 
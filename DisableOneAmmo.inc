public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
    static weapon, ammo;
    #if !defined _YSF_INCLUDED //SE NAO ESTIVER DEFINIDO
        for(new i = 0; i < 10; i++)
        {
            GetPlayerWeaponData(playerid, i, weapon, ammo); 
            if(weapon == weaponid)
            {
                if(ammo <= 1)
                {
                    GivePlayerWeapon(playerid, weaponid, 1);
                    SetPlayerArmedWeapon(playerid, 0);
                    return 0;
                }
                break;
            }
        }
    #else 
        GetPlayerWeaponData(playerid, GetWeaponSlot(weaponid), weapon, ammo);
        if(ammo <= 1) 
        {
            GivePlayerWeapon(playerid, weapon, 1);
            SetPlayerArmedWeapon(playerid, 0);
            return 0;
        }
    #endif
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
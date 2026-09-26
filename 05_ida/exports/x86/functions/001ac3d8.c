/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ac3d8. */
char __cdecl +[SCSIDisk probe:](id a1, SEL a2, id a3)
{
  SCSIDisk *v3; // esi
  int v4; // edi
  id v5; // eax
  _BYTE *v6; // ebx
  id v8; // [esp+Ch] [ebp-3Ch]
  char v9; // [esp+14h] [ebp-34h]
  id v10; // [esp+18h] [ebp-30h]
  int *v11; // [esp+1Ch] [ebp-2Ch]
  unsigned __int8 j; // [esp+20h] [ebp-28h]
  char k; // [esp+20h] [ebp-28h]
  unsigned __int8 i; // [esp+24h] [ebp-24h]
  id v15[8]; // [esp+28h] [ebp-20h]

  v3 = nullptr; /*0x1ac3e4*/
  v11 = sd_idmap(); /*0x1ac3eb*/
  v10 = objc_msgSend(a3, sel_directDevice); /*0x1ac3fb*/
  v9 = 0; /*0x1ac3fe*/
  for ( i = 0; (char)i < (int)objc_msgSend(v10, sel_numberOfTargets); ++i ) /*0x1ac402*/
  {
    v4 = 0; /*0x1ac42b*/
    for ( j = 0; (char)j <= 7; ++j ) /*0x1ac42d*/
    {
      if ( !v3 ) /*0x1ac43a*/
      {
        v3 = +[Object alloc](aScsidisk_0, sel_alloc); /*0x1ac44f*/
        -[IODevice setName:](v3, sel_setName_, "SCSIDisk"); /*0x1ac45e*/
        -[SCSIDisk initResources](v3, sel_initResources); /*0x1ac46b*/
        -[SCSIDisk setDevAndIdInfo:](v3, sel_setDevAndIdInfo_, &v11[9 * dword_1E5170]); /*0x1ac487*/
      }
      if ( !objc_msgSend(v10, sel_reserveTarget_lun_forOwner_, i, j, v3) ) /*0x1ac4a4*/
      {
        v5 = -[SCSIDisk SCSIDiskInit:targetId:lun:controller:]( /*0x1ac4c8*/
               v3,
               sel_SCSIDiskInit_targetId_lun_controller_,
               dword_1E5170,
               i,
               j,
               v10);
        if ( v5 ) /*0x1ac4d2*/
        {
          v8 = v5; /*0x1ac4f9*/
          objc_msgSend(v10, sel_releaseTarget_lun_forOwner_, i, j, v3); /*0x1ac4fc*/
          if ( v8 == (id)2 ) /*0x1ac50a*/
            break; /*0x1ac50a*/
        }
        else
        {
          v15[v4++] = v3; /*0x1ac4d4*/
          ++dword_1E5170; /*0x1ac4d9*/
          v3 = nullptr; /*0x1ac4df*/
          v9 = 1; /*0x1ac4e1*/
        }
      }
    }
    for ( k = 0; k < v4; ++k ) /*0x1ac51f*/
    {
      v6 = v15[k]; /*0x1ac528*/
      v6[394] |= 1u; /*0x1ac52c*/
      objc_msgSend(v6, sel_setDeviceKind_, "SCSIDisk"); /*0x1ac540*/
      objc_msgSend(v6, sel_setIsPhysical_, 1); /*0x1ac54f*/
      objc_msgSend(v6, sel_registerDevice); /*0x1ac55c*/
      v6[394] |= 2u; /*0x1ac561*/
    }
  }
  if ( v3 ) /*0x1ac582*/
    -[IODevice free](v3, sel_free); /*0x1ac58c*/
  return v9; /*0x1ac598*/
}

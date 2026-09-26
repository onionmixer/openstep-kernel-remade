/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x124154. */
int __cdecl in_bootp(int a1, void *a2, void *a3)
{
  int v3; // edi
  int v4; // eax
  int v5; // ebx
  __int16 v6; // ax
  __int16 v7; // ax
  int v9; // [esp+10h] [ebp-2Ch]
  int v10; // [esp+14h] [ebp-28h] BYREF
  int v11; // [esp+18h] [ebp-24h] BYREF
  _DWORD v12[4]; // [esp+1Ch] [ebp-20h] BYREF
  _WORD v13[8]; // [esp+2Ch] [ebp-10h] BYREF

  v9 = 0; /*0x12415d*/
  v3 = 0; /*0x124164*/
  v10 = 0; /*0x124166*/
  sub_124CB8(a1, a2); /*0x12417a*/
  v4 = sub_124338(a1, v12, &v11); /*0x124188*/
  v5 = v4; /*0x12418d*/
  if ( !v4 ) /*0x124194*/
  {
    v9 = sub_1244A0(a1, (int)a2, a3); /*0x1241e9*/
    v3 = kalloc(0x12Cu); /*0x1241f6*/
    while ( 1 ) /*0x12421f*/
    {
      v5 = sub_12470C(a1, v11, v9, v3, a3, (int)&v10); /*0x12421f*/
      if ( v5 ) /*0x124226*/
        break; /*0x124226*/
      if ( !*(_BYTE *)(v3 + 242) ) /*0x124233*/
      {
        if ( v10 ) /*0x124269*/
        {
          sub_124AD0(v10); /*0x12426c*/
          v10 = 0; /*0x124271*/
        }
        v5 = sub_124C2C(a1, v12, v11, v3 + 16); /*0x124290*/
        if ( !v5 ) /*0x124297*/
        {
          bcopy(v13, a2, 0x10u); /*0x1242a3*/
          goto LABEL_17; /*0x1242a3*/
        }
        break; /*0x124297*/
      }
      if ( v10 || (v5 = sub_124A60(&v10)) == 0 ) /*0x124248*/
      {
        v5 = sub_124AE8(v10, v9, v3); /*0x124258*/
        if ( !v5 ) /*0x12425f*/
          continue; /*0x12425f*/
      }
      break; /*0x12425f*/
    }
LABEL_18:
    if ( v11 ) /*0x1242b4*/
    {
      v6 = *(_WORD *)(a1 + 12); /*0x1242b9*/
      LOBYTE(v6) = v6 & 0xFE; /*0x1242bd*/
      v13[0] = v6; /*0x1242bf*/
      ifioctl(v11, -2145359600, v12); /*0x1242cd*/
    }
    goto LABEL_20; /*0x1242cd*/
  }
  if ( v4 == -1 ) /*0x124199*/
  {
    v5 = ifioctl(v11, -2145359604, v12); /*0x1241ae*/
    if ( !v5 ) /*0x1241b5*/
      bcopy(v13, a2, 0x10u); /*0x1241c1*/
    soclose(v11); /*0x1241cd*/
    return v5; /*0x1241d2*/
  }
LABEL_17:
  if ( v5 ) /*0x1242ad*/
    goto LABEL_18; /*0x1242ad*/
LABEL_20:
  v7 = *(_WORD *)(a1 + 12); /*0x1242d5*/
  HIBYTE(v7) &= ~0x40u; /*0x1242dc*/
  *(_WORD *)(a1 + 12) = v7; /*0x1242df*/
  if ( v11 ) /*0x1242e8*/
    soclose(v11); /*0x1242eb*/
  if ( v9 ) /*0x1242f7*/
    kfree(v9, 0x148u); /*0x124302*/
  if ( v3 ) /*0x12430c*/
    kfree(v3, 0x12Cu); /*0x124314*/
  if ( !v5 ) /*0x12431e*/
    sub_124AD0(v10); /*0x124324*/
  return v5; /*0x12432e*/
}

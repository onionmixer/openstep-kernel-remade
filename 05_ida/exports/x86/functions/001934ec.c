/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1934ec. */
void __cdecl sendsig(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned __int16 *v4; // ebx
  int v5; // edi
  int *v6; // eax
  int v7; // ecx
  unsigned int v8; // edx
  int v9; // eax
  thread_act_t v10; // [esp+Ch] [ebp-60h]
  unsigned int v11; // [esp+10h] [ebp-5Ch]
  unsigned int v12; // [esp+14h] [ebp-58h]
  _DWORD v13[14]; // [esp+18h] [ebp-54h] BYREF
  int v14; // [esp+50h] [ebp-1Ch]
  int v15; // [esp+54h] [ebp-18h]
  int v16; // [esp+58h] [ebp-14h]
  int v17; // [esp+5Ch] [ebp-10h]
  int v18; // [esp+60h] [ebp-Ch] BYREF
  int v19; // [esp+64h] [ebp-8h]
  unsigned int v20; // [esp+68h] [ebp-4h]

  v10 = active_threads; /*0x1934fb*/
  v3 = *(_DWORD *)(*(_DWORD *)(active_threads + 40) + 112); /*0x193501*/
  if ( v3 ) /*0x193506*/
    v4 = (unsigned __int16 *)(v3 + 132); /*0x193508*/
  else
    v4 = (unsigned __int16 *)thread_user_state(active_threads); /*0x19351c*/
  v5 = *(_DWORD *)(active_u + 332); /*0x193524*/
  if ( v5 || ((*(int *)(active_u + 316) >> (a2 - 1)) & 1) == 0 ) /*0x19353c*/
  {
    v11 = *((_DWORD *)v4 + 17) - 72; /*0x19355e*/
  }
  else
  {
    v11 = *(_DWORD *)(active_u + 328) - 72; /*0x193547*/
    *(_DWORD *)(active_u + 332) = 1; /*0x19354a*/
  }
  v12 = v11 - 12; /*0x193567*/
  v18 = a2; /*0x19356d*/
  if ( a2 == 4 || a2 == 8 ) /*0x193578*/
  {
    v19 = *(_DWORD *)(dword_1E875C + 116); /*0x193582*/
    *(_DWORD *)(dword_1E875C + 116) = 0; /*0x193585*/
  }
  else
  {
    v19 = 0; /*0x193590*/
  }
  v20 = v11; /*0x19359a*/
  if ( copyout((unsigned __int16 *)&v18, v12, 12) ) /*0x1935a7*/
    goto LABEL_27; /*0x1935a7*/
  v6 = *(int **)(*(_DWORD *)(v10 + 40) + 236); /*0x1935bd*/
  v7 = 0; /*0x1935c3*/
  if ( v6 ) /*0x1935c7*/
    v7 = *v6; /*0x1935c9*/
  if ( v7 && (v8 = *(_DWORD *)(v7 + 132), v8 <= 7) ) /*0x1935d8*/
    v9 = v7 + 132 * v8 + 136; /*0x1935e1*/
  else
    v9 = 0; /*0x1935ec*/
  if ( v9 && *(_DWORD *)(v9 + 72) ) /*0x1935f2*/
  {
    v5 |= 2u; /*0x1935f8*/
    *(_DWORD *)(v9 + 72) = 0; /*0x1935fb*/
  }
  v13[0] = v5; /*0x193602*/
  v13[1] = a3; /*0x193608*/
  v13[2] = *((_DWORD *)v4 + 11); /*0x19360e*/
  v13[3] = *((_DWORD *)v4 + 8); /*0x193614*/
  v13[4] = *((_DWORD *)v4 + 10); /*0x19361a*/
  v13[5] = *((_DWORD *)v4 + 9); /*0x193620*/
  v13[6] = *((_DWORD *)v4 + 4); /*0x193626*/
  v13[7] = *((_DWORD *)v4 + 5); /*0x19362c*/
  v13[8] = *((_DWORD *)v4 + 6); /*0x193632*/
  v13[9] = *((_DWORD *)v4 + 17); /*0x193638*/
  v13[10] = v4[36]; /*0x19363f*/
  v13[11] = *((_DWORD *)v4 + 16); /*0x193645*/
  v13[12] = *((_DWORD *)v4 + 14); /*0x19364b*/
  v13[13] = v4[30]; /*0x193652*/
  if ( (v4[33] & 2) != 0 ) /*0x193659*/
  {
    v14 = v4[40]; /*0x19365f*/
    v15 = v4[38]; /*0x193666*/
    v16 = v4[42]; /*0x19366d*/
    v17 = v4[44]; /*0x193674*/
    *((_DWORD *)v4 + 16) &= ~0x20000u; /*0x193677*/
  }
  else
  {
    v14 = v4[6]; /*0x193684*/
    v15 = v4[4]; /*0x19368b*/
    v16 = v4[2]; /*0x193692*/
    v17 = *v4; /*0x193698*/
  }
  if ( copyout((unsigned __int16 *)v13, v11, 72) ) /*0x1936a5*/
  {
LABEL_27:
    *(_DWORD *)(active_u + 64) = 0; /*0x1936e9*/
    *(_DWORD *)(*(_DWORD *)active_u + 32) &= ~8u; /*0x1936f7*/
    *(_DWORD *)(*(_DWORD *)active_u + 36) &= ~8u; /*0x193702*/
    *(_DWORD *)(*(_DWORD *)active_u + 28) &= ~8u; /*0x19370d*/
    psignal(*(_DWORD *)active_u, (const char *)4); /*0x19371b*/
  }
  else
  {
    *((_DWORD *)v4 + 14) = a1; /*0x1936b4*/
    v4[30] = 99; /*0x1936b7*/
    *((_DWORD *)v4 + 17) = v12; /*0x1936c0*/
    v4[36] = 107; /*0x1936c3*/
    v4[6] = 107; /*0x1936c9*/
    v4[4] = 107; /*0x1936cf*/
    v4[2] = 0; /*0x1936d5*/
    *v4 = 0; /*0x1936db*/
  }
}

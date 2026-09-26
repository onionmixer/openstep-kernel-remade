/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x103188. */
int __cdecl acct(const char *a1)
{
  int result; // eax
  int v2; // ebx
  unsigned int i; // ecx
  int v4; // esi
  uLongf *v5; // ecx
  int v6; // ecx
  const Bytef *v7; // [esp-1Ch] [ebp-80h]
  uLong v8; // [esp-18h] [ebp-7Ch]
  const Bytef *v9; // [esp-8h] [ebp-6Ch]
  int v10; // [esp-8h] [ebp-6Ch]
  uLong v11; // [esp-4h] [ebp-68h]
  const Bytef *v12; // [esp+0h] [ebp-64h]
  const Bytef *v13; // [esp+0h] [ebp-64h]
  uLong v14; // [esp+4h] [ebp-60h]
  uLong v15; // [esp+4h] [ebp-60h]
  int v16; // [esp+Ch] [ebp-58h]
  int v17; // [esp+14h] [ebp-50h]
  int *v18; // [esp+18h] [ebp-4Ch]
  Bytef *dest; // [esp+1Ch] [ebp-48h] BYREF
  uLongf *destLen; // [esp+20h] [ebp-44h]
  _BYTE v21[8]; // [esp+24h] [ebp-40h] BYREF
  int v22; // [esp+2Ch] [ebp-38h]
  int v23; // [esp+34h] [ebp-30h]

  if ( savacctp ) /*0x10319e*/
  {
    (*(void (__cdecl **)(_DWORD, _BYTE *))(*(_DWORD *)(*(_DWORD *)(savacctp + 36) + 4) + 12))( /*0x1031b1*/
      *(_DWORD *)(savacctp + 36),
      v21);
    result = v22 * acctresume / 100; /*0x1031c2*/
    if ( v23 > result ) /*0x1031ca*/
    {
      acctp = savacctp; /*0x1031d2*/
      savacctp = 0; /*0x1031d8*/
      result = printf("Accounting resumed\n"); /*0x1031e7*/
    }
  }
  v2 = acctp; /*0x1031ef*/
  v18 = (int *)acctp; /*0x1031f5*/
  if ( acctp ) /*0x1031fa*/
  {
    ++*(_WORD *)(acctp + 6); /*0x103200*/
    (*(void (__cdecl **)(_DWORD, _BYTE *))(*(_DWORD *)(*(_DWORD *)(v2 + 36) + 4) + 12))(*(_DWORD *)(v2 + 36), v21); /*0x103215*/
    if ( v23 > v22 * acctsuspend / 100 ) /*0x10322e*/
    {
      for ( i = 0; i <= 9; ++i ) /*0x10325c*/
        acctbuf[i] = *(_BYTE *)(i + active_u + 8); /*0x10326a*/
      v4 = active_u; /*0x103273*/
      v17 = active_u + 368; /*0x10327f*/
      *(_WORD *)&acctbuf[10] = compress(*(Bytef **)(active_u + 368), *(uLongf **)(active_u + 372), v12, v14); /*0x103295*/
      *(_WORD *)&acctbuf[12] = compress(*(Bytef **)(v4 + 376), *(uLongf **)(v4 + 380), v9, v11); /*0x1032ac*/
      microtime(&dest); /*0x1032b7*/
      timevalsub(&dest, active_u + 572); /*0x1032ca*/
      *(_WORD *)&acctbuf[14] = compress(dest, destLen, v7, v8); /*0x1032dc*/
      *(_DWORD *)&acctbuf[16] = *(_DWORD *)(active_u + 572); /*0x1032ec*/
      *(_WORD *)&acctbuf[20] = *(_WORD *)(*(_DWORD *)(active_u + 28) + 6); /*0x1032fc*/
      *(_WORD *)&acctbuf[22] = *(_WORD *)(*(_DWORD *)(active_u + 28) + 8); /*0x10330d*/
      v5 = *(uLongf **)(v4 + 380); /*0x103317*/
      dest = *(Bytef **)(v4 + 376); /*0x10331d*/
      destLen = v5; /*0x103320*/
      timevaladd(&dest, v17); /*0x10332e*/
      v6 = (int)destLen / tick + hz * (_DWORD)dest; /*0x103349*/
      if ( v6 ) /*0x103350*/
        *(_WORD *)&acctbuf[24] = (*(_DWORD *)(v4 + 396) + *(_DWORD *)(v4 + 392) + *(_DWORD *)(v4 + 388)) / v6; /*0x103369*/
      else
        *(_WORD *)&acctbuf[24] = 0; /*0x103370*/
      *(_WORD *)&acctbuf[26] = compress((Bytef *)(*(_DWORD *)(v17 + 48) + *(_DWORD *)(v17 + 44)), nullptr, v13, v15); /*0x10338f*/
      if ( *(_DWORD *)(active_u + 360) ) /*0x10339c*/
        *(_WORD *)&acctbuf[28] = *(_WORD *)(active_u + 364); /*0x1033ac*/
      else
        *(_WORD *)&acctbuf[28] = -1; /*0x1033b4*/
      acctbuf[30] = *(_BYTE *)(active_u + 580); /*0x1033c6*/
      v16 = *(_DWORD *)(active_u + 28); /*0x1033d2*/
      *(_DWORD *)(active_u + 28) = acctcred; /*0x1033e1*/
      *(_BYTE *)(dword_1E875C + 104) = vn_rdwr(1, v18, (int)acctbuf, 32, 0, 1, 3, nullptr); /*0x103400*/
      *(_DWORD *)(active_u + 28) = v16; /*0x10340c*/
      LOWORD(result) = vn_rele(v10); /*0x103416*/
    }
    else
    {
      savacctp = acctp; /*0x103236*/
      acctp = 0; /*0x10323c*/
      printf("Accounting suspended\n"); /*0x10324b*/
      LOWORD(result) = vn_rele((int)v18); /*0x103254*/
    }
  }
  return result; /*0x10341e*/
}

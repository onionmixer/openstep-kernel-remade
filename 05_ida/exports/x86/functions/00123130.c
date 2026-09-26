/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x123130. */
void __cdecl revarpinput(int a1, int a2)
{
  int v2; // edi
  __int16 v3; // ax
  int v4; // esi
  int v5; // ebx
  int *v6; // esi
  _BYTE *v7; // ebx
  _DWORD *v8; // ebx
  _WORD *v9; // [esp+10h] [ebp-1Ch]
  _BYTE v10[6]; // [esp+16h] [ebp-16h] BYREF
  _WORD v11[8]; // [esp+1Ch] [ebp-10h] BYREF

  v2 = a2; /*0x123139*/
  *(_DWORD *)(a2 + 4) += 4; /*0x12313c*/
  v3 = *(_WORD *)(a2 + 8); /*0x123140*/
  *(_WORD *)(a2 + 8) = v3 - 4; /*0x123148*/
  if ( v3 == 4 ) /*0x12314c*/
  {
    v4 = splimp(); /*0x123157*/
    if ( !*(_WORD *)(a2 + 10) ) /*0x123159*/
      panic(aMfree_7); /*0x123165*/
    --word_1E917C[*(__int16 *)(a2 + 10)]; /*0x123171*/
    ++word_1E917C[0]; /*0x123179*/
    *(_WORD *)(a2 + 10) = 0; /*0x123180*/
    if ( *(_DWORD *)(a2 + 4) > 0x7Fu ) /*0x12318a*/
      mclput(a2); /*0x12318d*/
    v5 = *(_DWORD *)a2; /*0x123195*/
    *(_DWORD *)a2 = mfree; /*0x12319d*/
    *(_DWORD *)(a2 + 4) = 0; /*0x12319f*/
    *(_DWORD *)(a2 + 124) = 0; /*0x1231a6*/
    mfree = a2; /*0x1231ad*/
    splx(v4); /*0x1231b4*/
    if ( m_want ) /*0x1231c3*/
    {
      m_want = 0; /*0x1231c5*/
      wakeup((int)&mfree); /*0x1231d4*/
    }
    v2 = v5; /*0x1231dc*/
  }
  v9 = (_WORD *)(*(_DWORD *)(v2 + 4) + v2); /*0x1231e3*/
  if ( *(_WORD *)(v2 + 8) <= 0x1Bu ) /*0x1231eb*/
    goto LABEL_30; /*0x1231eb*/
  if ( *(char *)(a1 + 12) < 0 ) /*0x1231f8*/
    goto LABEL_30; /*0x1231f8*/
  if ( __ROR2__(v9[1], 8) != 2048 ) /*0x12320d*/
    goto LABEL_30; /*0x12320d*/
  if ( !revarp ) /*0x12321a*/
    goto LABEL_30; /*0x12321a*/
  if ( __ROR2__(v9[3], 8) != 3 ) /*0x12322c*/
    goto LABEL_30; /*0x12322c*/
  v6 = (int *)&arptab; /*0x123232*/
  if ( &arptab >= (_UNKNOWN *)&master_processor ) /*0x12323d*/
    goto LABEL_30; /*0x12323d*/
  v7 = &unk_1E9C84; /*0x123243*/
  do /*0x123270*/
  {
    if ( (v7[7] & 4) != 0 && !bcmp(v7, v9 + 9, 6u) ) /*0x123258*/
      break; /*0x123262*/
    v7 += 20; /*0x123264*/
    v6 += 5; /*0x123267*/
  }
  while ( v6 < &master_processor ); /*0x123270*/
  if ( v6 >= &master_processor ) /*0x123278*/
    goto LABEL_30; /*0x123278*/
  bcopy(v9 + 4, v10, 6u); /*0x12328e*/
  bcopy(v6, v9 + 12, 4u); /*0x12329d*/
  v8 = *(_DWORD **)(a1 + 24); /*0x1232a5*/
  if ( !v8 ) /*0x1232ad*/
    goto LABEL_24; /*0x1232ad*/
  while ( v8[8] != a1 ) /*0x1232b3*/
  {
    v8 = (_DWORD *)v8[9]; /*0x1232b5*/
    if ( !v8 ) /*0x1232ba*/
      goto LABEL_23; /*0x1232ba*/
  }
  bcopy(v8 + 1, v9 + 7, 4u); /*0x1232ed*/
LABEL_23:
  if ( !v8 )
  {
LABEL_24:
    if ( revarpdebug )
      printf("revarp: can't find ifaddr\n");
LABEL_30:
    m_freem(v2); /*0x123370*/
    return; /*0x123371*/
  }
  bcopy((const void *)(a1 + 96), v9 + 4, 6u); /*0x123308*/
  bcopy((const void *)(a1 + 96), v11, 6u); /*0x123317*/
  v11[3] = -32715; /*0x12331f*/
  v9[3] = __ROR2__(4, 8); /*0x123334*/
  if ( revarpdebug ) /*0x123345*/
    printf("revarp reply to %X from %X\n", _byteswap_ulong(*((_DWORD *)v9 + 6)), _byteswap_ulong(*(_DWORD *)(v9 + 7))); /*0x123358*/
  (*(void (__stdcall **)(int, int))(a1 + 52))(a1, v2); /*0x12336c*/
}

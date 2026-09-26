/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1971e4. */
int __cdecl sub_1971E4(int a1)
{
  int v1; // esi
  int v2; // eax
  unsigned int v3; // esi
  int v4; // eax
  char *i; // ebx
  char v6; // al
  __int64 v7; // rax
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int *v12; // [esp+14h] [ebp-58h]
  int v13; // [esp+18h] [ebp-54h]
  char v14[80]; // [esp+1Ch] [ebp-50h] BYREF

  v13 = ttynty(a1); /*0x1971f6*/
  v1 = -1; /*0x1971f9*/
  if ( *(int *)(a1 + 24) > 0 )
  {
    v12 = (int *)(a1 + 24); /*0x197211*/
    do
    {
      v2 = (*(_DWORD *)(a1 + 60) & 0x2200020) != 0
        || (*(_DWORD *)(v13 + 16) & 0x10000000) == 0
        || (*(_DWORD *)(v13 + 16) & 0x300) == 0x300
         ? ndqb(v12, 0)
         : ndqb(v12, 128);
      v3 = v2; /*0x19725a*/
      if ( !v2 ) /*0x197261*/
        goto LABEL_15; /*0x197261*/
      v4 = 80; /*0x197263*/
      if ( v3 <= 0x4F ) /*0x19726b*/
        v4 = v3; /*0x19726d*/
      v1 = v4; /*0x19726f*/
      q_to_b((int)v12, v14, v4); /*0x19727a*/
      for ( i = v14; &v14[v1] > i; ++i ) /*0x19728a*/
        objc_msgSend(kmId, sel_kmPutc_, *i & 0x7F); /*0x1972a4*/
    }
    while ( *(int *)(a1 + 24) > 0 );
  }
  if ( !v1 ) /*0x1972c1*/
  {
LABEL_15:
    v6 = getc((FILE *)(a1 + 24)); /*0x1972c3*/
    v7 = ticks_to_ns_time(v6 & 0x7F); /*0x1972d9*/
    ns_timeout((int)ttrstrt, a1, v7); /*0x1972ec*/
    *(_BYTE *)(a1 + 64) |= 1u; /*0x1972f4*/
    goto LABEL_18; /*0x1972fb*/
  }
  if ( *(int *)(a1 + 24) > 0 ) /*0x197307*/
    calloutDispatchUnique((int)sub_1971E4, a1); /*0x19730f*/
LABEL_18:
  v8 = *(_DWORD *)(a1 + 64); /*0x197317*/
  v9 = v8; /*0x19731d*/
  LOBYTE(v9) = v8 & 0xDF; /*0x19731f*/
  *(_DWORD *)(a1 + 64) = v9; /*0x197322*/
  if ( *(_DWORD *)(a1 + 24) <= ttlowat[*(_BYTE *)(a1 + 74) & 0x1F] ) /*0x197336*/
  {
    if ( (v8 & 0x40) != 0 ) /*0x19733a*/
    {
      LOBYTE(v8) = v8 & 0x9F; /*0x19733c*/
      *(_DWORD *)(a1 + 64) = v8; /*0x19733e*/
      wakeup(a1 + 24); /*0x197348*/
    }
    v10 = *(_DWORD *)(a1 + 44); /*0x197353*/
    if ( v10 ) /*0x197358*/
    {
      selwakeup(v10, *(_DWORD *)(a1 + 64) & 0x1000); /*0x197365*/
      selthreadclear((_DWORD *)(a1 + 44)); /*0x197371*/
      *(_DWORD *)(a1 + 64) &= ~0x1000u; /*0x197376*/
    }
  }
  return 0; /*0x197382*/
}

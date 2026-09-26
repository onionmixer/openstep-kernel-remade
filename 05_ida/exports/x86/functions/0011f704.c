/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11f704. */
int __cdecl sub_11F704(int a1, int a2, int a3)
{
  __int16 v3; // dx
  __int16 v4; // dx
  int v5; // esi
  __int16 v6; // ax
  __int16 v7; // si
  __int16 v8; // bx
  int v9; // edi
  int v10; // eax
  int v11; // eax
  void *v12; // eax
  int v14; // [esp-10h] [ebp-230h]
  __int16 v15; // [esp+14h] [ebp-20Ch]
  _BYTE v16[512]; // [esp+18h] [ebp-208h] BYREF
  _WORD v17[3]; // [esp+218h] [ebp-8h] BYREF
  __int16 v18; // [esp+21Eh] [ebp-2h] BYREF

  if ( *(_DWORD *)(if_private(a1) + 12) != a2 ) /*0x11f722*/
    return 47; /*0x11f722*/
  nb_read(a3, 12, 2u, &v18); /*0x11f734*/
  v3 = __ROR2__(v18, 8); /*0x11f742*/
  v18 = v3; /*0x11f746*/
  if ( (unsigned __int16)(v3 - 4096) <= 0xFu ) /*0x11f753*/
  {
    v4 = v3 << 9; /*0x11f759*/
    v15 = v4; /*0x11f75d*/
    if ( !v4 ) /*0x11f764*/
      return 47; /*0x11f764*/
    v5 = v4; /*0x11f76a*/
    if ( (unsigned int)(v4 + 18) >= nb_size(a3) ) /*0x11f77e*/
      return 47; /*0x11f77e*/
    nb_read(a3, v5 + 14, 4u, v17); /*0x11f792*/
    v6 = __ROR2__(v17[0], 8); /*0x11f79e*/
    v18 = v6; /*0x11f7a2*/
    if ( v6 != 2048 && v6 != 2054 ) /*0x11f7b0*/
      return 47; /*0x11f7b0*/
    v7 = __ROR2__(v17[1], 8); /*0x11f7be*/
    if ( (unsigned int)(v15 + v7 + 14) > nb_size(a3) ) /*0x11f7e2*/
      return 47; /*0x11f7e2*/
    v8 = v7 - 4; /*0x11f7ea*/
    v9 = nb_map(a3); /*0x11f7f7*/
    if ( v15 <= 512 ) /*0x11f805*/
    {
      nb_read(a3, 14, v15, v16); /*0x11f860*/
      bcopy((const void *)(v9 + v15 + 18), (void *)(v9 + 14), v8); /*0x11f879*/
      bcopy(v16, (void *)(v9 + v8 + 14), v15); /*0x11f88b*/
    }
    else
    {
      nb_read(a3, v15 + 18, v8, v16); /*0x11f826*/
      bcopy((const void *)(v9 + 14), (void *)(v9 + v8 + 14), v15); /*0x11f83b*/
      bcopy(v16, (void *)(v9 + 14), v8); /*0x11f849*/
    }
    nb_shrink_bot(a3, 4); /*0x11f899*/
  }
  if ( v18 == 2048 ) /*0x11f8a9*/
  {
    nb_shrink_top(a3, 14); /*0x11f8be*/
    v10 = if_ipackets(a1); /*0x11f8c7*/
    if_ipackets_set(a1, v10 + 1); /*0x11f8d2*/
    inet_queue(a1, a3); /*0x11f8df*/
  }
  else
  {
    if ( v18 != 2054 ) /*0x11f8af*/
      return 47; /*0x11f955*/
    v11 = if_ipackets(a1); /*0x11f8ec*/
    if_ipackets_set(a1, v11 + 1); /*0x11f8f7*/
    if ( (if_flags(a1) & 0x4000) != 0 ) /*0x11f90b*/
    {
      nb_free(a3); /*0x11f948*/
    }
    else
    {
      nb_shrink_top(a3, 14); /*0x11f913*/
      v14 = *(_DWORD *)(if_private(a1) + 8); /*0x11f92b*/
      v12 = (void *)if_private(a1); /*0x11f930*/
      arpinput(a1, v12, v14, a3); /*0x11f93d*/
    }
  }
  return 0; /*0x11f960*/
}

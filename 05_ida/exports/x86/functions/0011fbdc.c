/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11fbdc. */
int __cdecl sub_11FBDC(int a1, int a2, int a3)
{
  int v3; // eax
  NXHashTable *v4; // eax
  char *v5; // eax
  _BYTE *v6; // edx
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // [esp-14h] [ebp-4Ch]
  int v12; // [esp+Ch] [ebp-2Ch]
  int v13; // [esp+10h] [ebp-28h] BYREF
  int v14; // [esp+14h] [ebp-24h] BYREF
  _BYTE v15[2]; // [esp+18h] [ebp-20h] BYREF
  _BYTE data[6]; // [esp+1Ah] [ebp-1Eh] BYREF
  char v17; // [esp+20h] [ebp-18h]
  char v18; // [esp+26h] [ebp-12h] BYREF
  char v19; // [esp+27h] [ebp-11h]

  v12 = *(_DWORD *)(if_private(a1) + 20); /*0x11fbfa*/
  if ( !*(_WORD *)a3 ) /*0x11fc02*/
  {
    bcopy((const void *)(a3 + 2), data, 6u); /*0x11fc17*/
    word_1DB89C = __ROR2__(*(_WORD *)(a3 + 14), 8); /*0x11fc29*/
    if ( word_1DB89C == __ROR2__(2054, 8) ) /*0x11fc3c*/
    {
      nb_write(a2, 0, 2u, &unk_1DB8A0); /*0x11fc4f*/
      if ( (*(_BYTE *)if_private(a1) & 1) != 0 ) /*0x11fc63*/
      {
        v17 |= 0x80u; /*0x11fc65*/
        v18 = -126; /*0x11fc69*/
        v19 = 112; /*0x11fc6d*/
      }
      else
      {
        v17 &= ~0x80u; /*0x11fc78*/
      }
    }
    goto LABEL_20; /*0x11fc71*/
  }
  if ( *(_WORD *)a3 != 2 ) /*0x11fc07*/
  {
    nb_free(a2); /*0x11fd54*/
    return 47; /*0x11fd5e*/
  }
  v14 = *(_DWORD *)(a3 + 4); /*0x11fc87*/
  v11 = *(_DWORD *)(if_private(a1) + 16); /*0x11fca6*/
  v3 = if_private(a1); /*0x11fca8*/
  if ( !arpresolve(a1, (void *)(v3 + 8), v11, a2, &v14, data, (int)&v13) ) /*0x11fcb5*/
    return 0; /*0x11fcc3*/
  if ( (*(_BYTE *)if_private(a1) & 1) == 0 ) /*0x11fcd4*/
    goto LABEL_18; /*0x11fcd4*/
  if ( data[0] >= 0 ) /*0x11fce1*/
  {
    v4 = *(NXHashTable **)(if_private(a1) + 4); /*0x11fcfd*/
    if ( data[0] < 0 ) /*0x11fd04*/
      goto LABEL_19; /*0x11fd04*/
    v5 = (char *)NXHashGet(v4, data); /*0x11fd08*/
    v6 = nullptr; /*0x11fd10*/
    if ( v5 ) /*0x11fd14*/
      v6 = v5 + 12; /*0x11fd16*/
    if ( v6 ) /*0x11fd1b*/
    {
      bcopy(v6, &v18, *v6 & 0x1F); /*0x11fd28*/
      v17 |= 0x80u; /*0x11fd2d*/
      goto LABEL_19; /*0x11fd34*/
    }
LABEL_18:
    v17 &= ~0x80u; /*0x11fd38*/
    goto LABEL_19; /*0x11fd38*/
  }
  v17 |= 0x80u; /*0x11fce3*/
  v18 = -62; /*0x11fce7*/
  v19 = 112; /*0x11fceb*/
LABEL_19:
  word_1DB89C = __ROR2__(2048, 8); /*0x11fd3c*/
LABEL_20:
  nb_grow_top(a2, 8); /*0x11fd60*/
  nb_write(a2, 0, 8u, &unk_1DB896); /*0x11fd78*/
  v15[0] = *(_BYTE *)(if_private(a1) + 24); /*0x11fd8c*/
  v15[1] = 64; /*0x11fd8f*/
  v8 = if_output(v12, a2, v15); /*0x11fda4*/
  if ( v8 ) /*0x11fdab*/
  {
    v9 = if_oerrors(a1); /*0x11fdae*/
    if_oerrors_set(a1, v9 + 1); /*0x11fdb6*/
  }
  else
  {
    v10 = if_opackets(a1); /*0x11fdc1*/
    if_opackets_set(a1, v10 + 1); /*0x11fdc9*/
  }
  return v8; /*0x11fdd3*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11ce68. */
int __cdecl mknod(const char *a1, mode_t a2, dev_t a3)
{
  int v3; // ebx
  int v4; // eax
  int result; // eax
  __int16 v6; // dx
  int v7; // [esp+4h] [ebp-44h] BYREF
  int v8; // [esp+8h] [ebp-40h] BYREF
  __int16 v9; // [esp+Ch] [ebp-3Ch]
  __int16 v10; // [esp+40h] [ebp-8h]

  v3 = *(_DWORD *)(dword_1E875C + 36); /*0x11ce74*/
  v4 = *(_DWORD *)(v3 + 4); /*0x11ce77*/
  if ( (v4 & 0xF000) == 0 ) /*0x11ce7d*/
  {
    BYTE1(v4) |= 0x80u; /*0x11ce7f*/
    *(_DWORD *)(v3 + 4) = v4; /*0x11ce82*/
  }
  if ( (*(_DWORD *)(v3 + 4) & 0xF000) == 0x1000 || (result = suser()) != 0 ) /*0x11ce9b*/
  {
    vattr_null(&v8); /*0x11cea5*/
    v8 = mftovt_tab[(*(_DWORD *)(v3 + 4) & 0xF000) >> 13]; /*0x11cebc*/
    v6 = *(_WORD *)(v3 + 4); /*0x11cebf*/
    HIBYTE(v6) &= 0xFu; /*0x11cec3*/
    v9 = ~*(_WORD *)(active_u + 366) & v6; /*0x11ced8*/
    switch ( v8 ) /*0x11cee7*/
    {
      case 0: /*0x11cee7*/
        result = dword_1E875C; /*0x11cf30*/
        *(_BYTE *)(dword_1E875C + 104) = 22; /*0x11cf35*/
        break; /*0x11cf39*/
      case 2: /*0x11cee7*/
        result = dword_1E875C; /*0x11cf18*/
        *(_BYTE *)(dword_1E875C + 104) = 21; /*0x11cf1d*/
        break; /*0x11cf21*/
      case 3: /*0x11cee7*/
      case 4: /*0x11cee7*/
      case 7: /*0x11cee7*/
      case 9: /*0x11cee7*/
        v10 = *(_WORD *)(v3 + 8); /*0x11cf28*/
        goto LABEL_9; /*0x11cf2c*/
      default:
LABEL_9:
        *(_BYTE *)(dword_1E875C + 104) = vn_create(*(_DWORD *)v3, 0, &v8, 1, 0, &v7); /*0x11cf3c*/
        result = dword_1E875C; /*0x11cf5c*/
        if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11cf64*/
          LOWORD(result) = vn_rele(v7); /*0x11cf6e*/
        break; /*0x11cf6e*/
    }
  }
  return result; /*0x11cf73*/
}

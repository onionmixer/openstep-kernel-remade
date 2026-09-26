/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13ec50. */
int __cdecl diraddentry(unsigned int a1, char *__src, int a3, int a4, unsigned int a5, unsigned int a6)
{
  int result; // eax
  size_t v7; // eax

  if ( *(_DWORD *)(a1 + 48) != *(_DWORD *)(a5 + 48) ) /*0x13ec65*/
    return 18; /*0x13ec67*/
  if ( (*(_WORD *)(a5 + 100) & 0xF000) != 0x4000 || (result = sub_13E9F8(a5, a6, a1)) == 0 ) /*0x13ec92*/
  {
    result = sub_13ED2C(a1, a4); /*0x13ec9a*/
    if ( !result ) /*0x13eca4*/
    {
      *(_WORD *)(*(_DWORD *)(a4 + 16) + 6) = a3; /*0x13ecad*/
      v7 = a3 + 4; /*0x13ecb4*/
      LOBYTE(v7) = (a3 + 4) & 0xFC; /*0x13ecb7*/
      strncpy((char *)(*(_DWORD *)(a4 + 16) + 8), __src, v7); /*0x13ecc5*/
      **(_DWORD **)(a4 + 16) = *(_DWORD *)(a5 + 72); /*0x13ecd0*/
      dnlc_enter(a1 + 12, __src, a5 + 12, nullptr); /*0x13ece0*/
      byte_swap_dir_block_out(*(_DWORD *)(a4 + 12)); /*0x13ece9*/
      bwrite(*(int **)(a4 + 12)); /*0x13ecf5*/
      *(_DWORD *)(a4 + 12) = 0; /*0x13ecfa*/
      LOBYTE(result) = *(_BYTE *)(dword_1E875C + 104); /*0x13ed06*/
      if ( (_BYTE)result ) /*0x13ed0b*/
      {
        return (char)result; /*0x13ed1c*/
      }
      else
      {
        *(_BYTE *)(a1 + 68) |= 0x42u; /*0x13ed0d*/
        *(_DWORD *)(a1 + 76) = 0; /*0x13ed11*/
        return 0; /*0x13ed18*/
      }
    }
  }
  return result; /*0x13ed22*/
}

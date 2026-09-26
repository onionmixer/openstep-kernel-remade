/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11eb50. */
int __cdecl physio(
        void (__cdecl *f_strategy)(buf_t),
        buf_t bp,
        dev_t dev,
        int flags,
        u_int (__cdecl *f_minphys)(buf_t),
        uio *uio,
        int blocksize)
{
  int result; // eax
  _DWORD *v8; // edi
  int v9; // eax
  int v10; // ecx
  int v11; // ebx
  int v12; // ebx
  int v13; // [esp+Ch] [ebp-Ch]
  int v14; // [esp+10h] [ebp-8h]

  v14 = 0; /*0x11eb64*/
  while ( 1 ) /*0x11eb6b*/
  {
    if ( !*((_DWORD *)uio + 1) ) /*0x11eb6e*/
      return 0; /*0x11eb76*/
    v8 = *(_DWORD **)uio; /*0x11eb7f*/
    if ( *((_DWORD *)uio + 3) != 1 && !useracc(*v8, v8[1], flags != 1) ) /*0x11eb9b*/
      break; /*0x11eb9b*/
    v13 = splbio(); /*0x11ebb9*/
    while ( 1 ) /*0x11ebcf*/
    {
      v9 = *(_DWORD *)bp; /*0x11ebcf*/
      if ( (*(_DWORD *)bp & 8) == 0 ) /*0x11ebd3*/
        break; /*0x11ebd3*/
      LOBYTE(v9) = v9 | 0x40; /*0x11ebc0*/
      *(_DWORD *)bp = v9; /*0x11ebc2*/
      sleep((unsigned int)bp); /*0x11ebc7*/
    }
    splx(v13); /*0x11ebd9*/
    *((_WORD *)bp + 14) = 0; /*0x11ebde*/
    *((_DWORD *)bp + 11) = *(_DWORD *)active_u; /*0x11ebeb*/
    *((_DWORD *)bp + 8) = *v8; /*0x11ebf0*/
    if ( (int)v8[1] > 0 ) /*0x11ebfa*/
    {
      do /*0x11ecd9*/
      {
        v10 = flags; /*0x11ec00*/
        LOBYTE(v10) = flags | 0x18; /*0x11ec03*/
        *(_DWORD *)bp = v10; /*0x11ec06*/
        *((_WORD *)bp + 15) = dev; /*0x11ec0c*/
        *((_DWORD *)bp + 9) = *((_DWORD *)uio + 2) / (unsigned int)blocksize; /*0x11ec1b*/
        *((_DWORD *)bp + 5) = v8[1]; /*0x11ec21*/
        f_minphys(bp); /*0x11ec28*/
        v11 = *((_DWORD *)bp + 5); /*0x11ec2a*/
        if ( *((_DWORD *)uio + 3) == 1 ) /*0x11ec37*/
        {
          *(_DWORD *)bp |= 0x4000000u; /*0x11ec39*/
        }
        else
        {
          *(_DWORD *)(*(_DWORD *)active_u + 40) |= 0x800u; /*0x11ec4b*/
          v14 = *((_DWORD *)bp + 8); /*0x11ec56*/
          vslock(v14, v11); /*0x11ec5a*/
        }
        physstrat((unsigned int)bp, f_strategy, 20); /*0x11ec69*/
        if ( *((_DWORD *)uio + 3) != 1 ) /*0x11ec78*/
        {
          vsunlock(v14, v11, flags); /*0x11ec83*/
          *(_DWORD *)(*(_DWORD *)active_u + 40) &= ~0x800u; /*0x11ec8f*/
        }
        splbio(); /*0x11ec99*/
        if ( (*(_BYTE *)bp & 0x40) != 0 ) /*0x11eca1*/
          wakeup((int)bp); /*0x11eca4*/
        splx(v13); /*0x11ecb0*/
        v12 = v11 - *((_DWORD *)bp + 10); /*0x11ecb5*/
        *((_DWORD *)bp + 8) += v12; /*0x11ecb8*/
        v8[1] -= v12; /*0x11ecbb*/
        *((_DWORD *)uio + 5) -= v12; /*0x11ecc1*/
        *((_DWORD *)uio + 2) += v12; /*0x11ecc4*/
      }
      while ( !*((_DWORD *)bp + 10) && (*(_BYTE *)bp & 4) == 0 && (int)v8[1] > 0 ); /*0x11ecd9*/
    }
    *(_DWORD *)bp &= 0xFFFFFFA7; /*0x11ecdf*/
    result = geterror((int)bp); /*0x11ece3*/
    if ( *((_DWORD *)bp + 10) || result ) /*0x11ecf3*/
      return result; /*0x11ecf3*/
    *(_DWORD *)uio += 8; /*0x11ecf8*/
    --*((_DWORD *)uio + 1); /*0x11ecfb*/
  }
  return 14; /*0x11ed07*/
}

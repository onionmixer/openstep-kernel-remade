/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x185c1c. */
int __cdecl kdp_machine_read_regs(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  unsigned __int16 *v4; // eax

  if ( a2 == -2 ) /*0x185c2b*/
  {
    qmemcpy(a3, &unk_1D1434, 0x6Cu); /*0x185cd2*/
    *a4 = 108; /*0x185cd4*/
    return 0; /*0x185cda*/
  }
  else if ( a2 == -1 ) /*0x185c34*/
  {
    v4 = (unsigned __int16 *)dword_1F66AC; /*0x185c3a*/
    qmemcpy(a3, &unk_1D13F4, 0x40u); /*0x185c4f*/
    *a3 = *((_DWORD *)v4 + 11); /*0x185c54*/
    a3[1] = *((_DWORD *)v4 + 8); /*0x185c5c*/
    a3[2] = *((_DWORD *)v4 + 10); /*0x185c62*/
    a3[3] = *((_DWORD *)v4 + 9); /*0x185c68*/
    a3[4] = *((_DWORD *)v4 + 4); /*0x185c6e*/
    a3[5] = *((_DWORD *)v4 + 5); /*0x185c74*/
    a3[6] = *((_DWORD *)v4 + 6); /*0x185c7a*/
    a3[7] = v4 + 34; /*0x185c80*/
    a3[8] = v4[36]; /*0x185c87*/
    a3[9] = *((_DWORD *)v4 + 16); /*0x185c8d*/
    a3[10] = *((_DWORD *)v4 + 14); /*0x185c93*/
    a3[11] = v4[30]; /*0x185c9a*/
    a3[12] = v4[6]; /*0x185ca1*/
    a3[13] = v4[4]; /*0x185ca8*/
    a3[14] = v4[2]; /*0x185caf*/
    a3[15] = *v4; /*0x185cb5*/
    *a4 = 64; /*0x185cb8*/
    return 0; /*0x185cbe*/
  }
  else
  {
    return 3; /*0x185ce0*/
  }
}

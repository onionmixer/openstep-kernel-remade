/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19ed8c. */
int __cdecl VBEModeInfo2IODisplayInfo(unsigned __int16 *a1, int a2)
{
  int result; // eax
  int v3; // edx
  int v4; // edx
  int v5; // ecx
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  int v11; // edx

  *(_DWORD *)a2 = a1[2]; /*0x19ed9c*/
  *(_DWORD *)(a2 + 4) = a1[3]; /*0x19eda2*/
  *(_DWORD *)(a2 + 8) = a1[2]; /*0x19eda9*/
  *(_DWORD *)(a2 + 12) = a1[4]; /*0x19edb0*/
  *(_DWORD *)(a2 + 16) = 0; /*0x19edb3*/
  *(_DWORD *)(a2 + 20) = *((_DWORD *)a1 + 5); /*0x19edbd*/
  result = *((unsigned __int8 *)a1 + 10) - 2; /*0x19edc4*/
  switch ( *((_BYTE *)a1 + 10) ) /*0x19edd0*/
  {
    case 2: /*0x19edd0*/
      *(_DWORD *)(a2 + 24) = 0; /*0x19ee54*/
      goto LABEL_8; /*0x19ee5b*/
    case 8: /*0x19edd0*/
      *(_DWORD *)(a2 + 24) = 1; /*0x19ee60*/
      goto LABEL_8; /*0x19ee67*/
    case 0xC: /*0x19edd0*/
      *(_DWORD *)(a2 + 24) = 2; /*0x19ee6c*/
      goto LABEL_8; /*0x19ee73*/
    case 0xF: /*0x19edd0*/
    case 0x10: /*0x19edd0*/
      *(_DWORD *)(a2 + 24) = 3; /*0x19ee78*/
      goto LABEL_8; /*0x19ee7f*/
    case 0x18: /*0x19edd0*/
    case 0x20: /*0x19edd0*/
      *(_DWORD *)(a2 + 24) = 4; /*0x19ee84*/
LABEL_8:
      if ( (a1[1] & 8) != 0 ) /*0x19eea0*/
      {
        *(_DWORD *)(a2 + 28) = 2; /*0x19eea6*/
        if ( *((_BYTE *)a1 + 11) == 4 ) /*0x19eeb1*/
        {
          v3 = 0; /*0x19eeb3*/
          if ( *((_BYTE *)a1 + 10) ) /*0x19eeb5*/
          {
            do /*0x19eecc*/
            {
              *(_BYTE *)(v3 + a2 + 32) = 80; /*0x19eec0*/
              ++v3; /*0x19eec5*/
            }
            while ( v3 < *((unsigned __int8 *)a1 + 10) ); /*0x19eecc*/
          }
        }
        else
        {
          v4 = 0; /*0x19eed4*/
          if ( *((_BYTE *)a1 + 10) ) /*0x19eed6*/
          {
            do /*0x19eee8*/
            {
              *(_BYTE *)(v4 + a2 + 32) = 45; /*0x19eedc*/
              ++v4; /*0x19eee1*/
            }
            while ( v4 < *((unsigned __int8 *)a1 + 10) ); /*0x19eee8*/
          }
          v5 = *((unsigned __int8 *)a1 + 10) - *((unsigned __int8 *)a1 + 13) - 1; /*0x19eef4*/
          v6 = 0; /*0x19eef7*/
          if ( *((_BYTE *)a1 + 12) ) /*0x19eef9*/
          {
            do /*0x19ef10*/
              *(_BYTE *)(v5 - v6++ + a2 + 32) = 82; /*0x19ef04*/
            while ( v6 < *((unsigned __int8 *)a1 + 12) ); /*0x19ef10*/
          }
          v7 = *((unsigned __int8 *)a1 + 10) - *((unsigned __int8 *)a1 + 15) - 1; /*0x19ef1c*/
          v8 = 0; /*0x19ef1f*/
          if ( *((_BYTE *)a1 + 14) ) /*0x19ef21*/
          {
            do /*0x19ef38*/
              *(_BYTE *)(v7 - v8++ + a2 + 32) = 71; /*0x19ef2c*/
            while ( v8 < *((unsigned __int8 *)a1 + 14) ); /*0x19ef38*/
          }
          v9 = *((unsigned __int8 *)a1 + 10) - *((unsigned __int8 *)a1 + 17) - 1; /*0x19ef44*/
          v10 = 0; /*0x19ef47*/
          if ( *((_BYTE *)a1 + 16) ) /*0x19ef49*/
          {
            do /*0x19ef60*/
              *(_BYTE *)(v9 - v10++ + a2 + 32) = 66; /*0x19ef54*/
            while ( v10 < *((unsigned __int8 *)a1 + 16) ); /*0x19ef60*/
          }
        }
      }
      else
      {
        *(_DWORD *)(a2 + 28) = 1; /*0x19ef64*/
        v11 = 0; /*0x19ef6b*/
        if ( *((_BYTE *)a1 + 10) ) /*0x19ef6d*/
        {
          do /*0x19ef80*/
          {
            *(_BYTE *)(v11 + a2 + 32) = 87; /*0x19ef74*/
            ++v11; /*0x19ef79*/
          }
          while ( v11 < *((unsigned __int8 *)a1 + 10) ); /*0x19ef80*/
        }
      }
      *(_DWORD *)(a2 + 96) = 2; /*0x19ef82*/
      *(_DWORD *)(a2 + 100) = *a1; /*0x19ef8c*/
      result = a1[4]; /*0x19ef93*/
      *(_DWORD *)(a2 + 104) = result * a1[3]; /*0x19ef9a*/
      break; /*0x19ef9a*/
    default:
      *(_BYTE *)(a2 + 128) |= 0x10u; /*0x19ee90*/
      break; /*0x19ee97*/
  }
  return result; /*0x19efa0*/
}

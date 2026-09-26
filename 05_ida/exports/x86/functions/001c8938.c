/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8938. */
unsigned int __cdecl sub_1C8938(char *a1, unsigned int a2, unsigned int a3)
{
  _BYTE *v3; // edx
  char v4; // al
  unsigned int v5; // eax
  unsigned int v6; // ecx
  _BYTE *v7; // edx
  _BYTE *v8; // edx
  int v9; // eax
  _BYTE *v10; // edx

  v3 = (_BYTE *)a2; /*0x1c8940*/
  v4 = *a1; /*0x1c8946*/
  if ( *a1 != 42 ) /*0x1c894a*/
  {
    if ( *a1 > 42 ) /*0x1c894c*/
    {
      if ( v4 == 64 ) /*0x1c8956*/
      {
        v5 = (unsigned int)objc_msgSend((id)a2, sel_hash); /*0x1c8960*/
        return v5 % a3; /*0x1c89b9*/
      }
LABEL_16:
      v5 = a2 ^ HIWORD(a2); /*0x1c89b0*/
      return v5 % a3; /*0x1c89b5*/
    }
    if ( v4 != 37 ) /*0x1c8950*/
      goto LABEL_16; /*0x1c8950*/
  }
  if ( a2 ) /*0x1c896a*/
  {
    v6 = 0; /*0x1c896c*/
    while ( *v3 ) /*0x1c8970*/
    {
      v6 ^= (unsigned __int8)*v3; /*0x1c8978*/
      v7 = v3 + 1; /*0x1c897a*/
      if ( !*v7 ) /*0x1c897b*/
        break; /*0x1c897b*/
      v6 ^= (unsigned __int8)*v7 << 8; /*0x1c8986*/
      v8 = v7 + 1; /*0x1c8988*/
      if ( !*v8 ) /*0x1c8989*/
        break; /*0x1c8989*/
      v9 = (unsigned __int8)*v8 << 16; /*0x1c8991*/
      v6 ^= v9; /*0x1c8994*/
      v10 = v8 + 1; /*0x1c8996*/
      if ( !*v10 ) /*0x1c8997*/
        break; /*0x1c8997*/
      LOBYTE(v9) = *v10; /*0x1c899c*/
      v6 ^= v9 << 24; /*0x1c89a1*/
      v3 = v10 + 1; /*0x1c89a3*/
    }
    v5 = v6; /*0x1c89a8*/
    return v5 % a3; /*0x1c89aa*/
  }
  return 0; /*0x1c89c0*/
}

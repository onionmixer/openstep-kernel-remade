/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18b080. */
int __cdecl getval(_BYTE *a1, _DWORD *a2)
{
  char *v2; // ecx
  int v3; // eax
  int v4; // ebx
  char *v5; // ecx
  unsigned int v6; // esi
  char v7; // al
  char v8; // al
  unsigned __int8 v9; // dl
  unsigned __int8 v10; // dl
  int v12; // [esp+Ch] [ebp-4h]

  v12 = 1; /*0x18b08c*/
  if ( *a1 != 61 ) /*0x18b096*/
  {
    *a2 = 1; /*0x18b16f*/
    return 0; /*0x18b16f*/
  }
  v2 = a1 + 1; /*0x18b09c*/
  if ( a1[1] == 45 ) /*0x18b0a0*/
  {
    v12 = -1; /*0x18b0a2*/
    v2 = a1 + 2; /*0x18b0a9*/
  }
  v3 = *v2; /*0x18b0aa*/
  v4 = v3 - 48; /*0x18b0ad*/
  v5 = v2 + 1; /*0x18b0b0*/
  v6 = 10; /*0x18b0b1*/
  if ( v3 == 48 ) /*0x18b0b8*/
  {
    v7 = *v5; /*0x18b0ba*/
    if ( *v5 >= 48 ) /*0x18b0be*/
    {
      if ( v7 <= 55 ) /*0x18b0c2*/
      {
        v4 = v7 - 48; /*0x18b0df*/
        ++v5; /*0x18b0e2*/
        v6 = 8; /*0x18b0e3*/
        goto LABEL_16; /*0x18b0e8*/
      }
      if ( v7 == 98 ) /*0x18b0c6*/
      {
        v6 = 2; /*0x18b0d4*/
        ++v5; /*0x18b0d9*/
        goto LABEL_16; /*0x18b0da*/
      }
      if ( v7 == 120 ) /*0x18b0ca*/
      {
        v6 = 16; /*0x18b0cc*/
        ++v5; /*0x18b0d1*/
        goto LABEL_16; /*0x18b0d2*/
      }
    }
    v8 = *v5; /*0x18b0ec*/
    if ( *v5 != 32 && v8 && v8 != 9 && v8 != 44 ) /*0x18b0fc*/
      return 1; /*0x18b169*/
  }
  while ( 1 ) /*0x18b100*/
  {
LABEL_16:
    v9 = *v5++; /*0x18b100*/
    if ( v9 > 0x2Fu && v9 <= 0x39u ) /*0x18b10b*/
    {
      v10 = v9 - 48; /*0x18b10d*/
      goto LABEL_28; /*0x18b110*/
    }
    if ( (unsigned __int8)(v9 - 97) <= 5u ) /*0x18b11a*/
    {
      v10 = v9 - 87; /*0x18b11c*/
      goto LABEL_28; /*0x18b11f*/
    }
    if ( (unsigned __int8)(v9 - 65) > 5u ) /*0x18b12a*/
      break; /*0x18b12a*/
    v10 = v9 - 55; /*0x18b144*/
LABEL_28:
    if ( v10 >= v6 ) /*0x18b14c*/
      return 1; /*0x18b14c*/
    v4 = v10 + v6 * v4; /*0x18b151*/
  }
  if ( v9 != 32 && v9 && v9 != 9 && v9 != 44 ) /*0x18b13d*/
    return 1; /*0x18b13d*/
  *a2 = v12 * v4; /*0x18b15f*/
  return 0; /*0x18b17a*/
}

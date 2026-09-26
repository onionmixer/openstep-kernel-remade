/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12fbf8. */
int newname()
{
  int v0; // esi
  _BYTE *v1; // ebx
  char *i; // eax
  int j; // edx
  int v5; // [esp+8h] [ebp-8h] BYREF

  v0 = kalloc(0xFFu); /*0x12fc0a*/
  v1 = (_BYTE *)v0; /*0x12fc0c*/
  for ( i = aNfs; (unsigned int)i < 0x1DC545; ++v1 ) /*0x12fc1b*/
    *v1 = *i++; /*0x12fc22*/
  if ( !dword_1E59B0 ) /*0x12fc34*/
  {
    getthetime(&v5); /*0x12fc3a*/
    dword_1E59B0 = (unsigned __int16)v5; /*0x12fc43*/
  }
  for ( j = dword_1E59B0++; j; j >>= 4 ) /*0x12fc57*/
    *v1++ = byte_1DC546[j & 0xF]; /*0x12fc67*/
  *v1 = 0; /*0x12fc6f*/
  return v0; /*0x12fc77*/
}

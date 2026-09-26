/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ac28. */
char __usercall sub_18AC28@<al>(__int16 a1@<fpstat>)
{
  unsigned int v1; // kr00_4
  unsigned __int32 v2; // eax
  unsigned int v3; // kr04_4
  unsigned int v4; // kr08_4
  char result; // al

  v1 = __readeflags(); /*0x18ac31*/
  __writeeflags(v1 | 0x40000); /*0x18ac3a*/
  __writeeflags(v1 & 0xFFFBFFFF); /*0x18ac4a*/
  v2 = __readcr0(); /*0x18ac54*/
  __wbinvd(); /*0x18ac5c*/
  __writecr0(v2 & 0x9FFFFFFF); /*0x18ac5e*/
  fp_configure(a1); /*0x18ac61*/
  machine_slot[0] = 1; /*0x18ac66*/
  dword_1E8E0C[0] = 1; /*0x18ac70*/
  dword_1E8E04 = 7; /*0x18ac7a*/
  v3 = __readeflags(); /*0x18ac84*/
  __writeeflags(v3 | 0x200000); /*0x18ac8d*/
  v4 = __readeflags(); /*0x18ac8e*/
  if ( (v4 & 0x200000) == 0 ) /*0x18ac96*/
    goto LABEL_4; /*0x18ac96*/
  _EAX = 1; /*0x18ac98*/
  __asm { cpuid } /*0x18ac9d*/
  __writeeflags(v4 & 0xFFDFFFFF); /*0x18aca8*/
  result = BYTE1(_EAX) & 0xF; /*0x18acac*/
  if ( (BYTE1(_EAX) & 0xF) == 5 ) /*0x18acbb*/
  {
    dword_1E8E08 = 5; /*0x18acbd*/
  }
  else
  {
LABEL_4:
    result = cpu_config & 3; /*0x18acd2*/
    if ( (cpu_config & 3) == 2 ) /*0x18acd6*/
      dword_1E8E08 = 4; /*0x18acd8*/
    else
      dword_1E8E08 = 132; /*0x18ace4*/
  }
  return result; /*0x18acf1*/
}

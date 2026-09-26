/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14d1a4. */
_DWORD *__cdecl ipc_port_alloc_special(int a1)
{
  _DWORD *v1; // eax
  _DWORD *v2; // ebx

  v1 = (_DWORD *)zalloc(ipc_object_zones[0]); /*0x14d1af*/
  v2 = v1; /*0x14d1b4*/
  if ( !v1 ) /*0x14d1bb*/
    return nullptr; /*0x14d238*/
  *v1 = 0; /*0x14d1bd*/
  v1[1] = 1; /*0x14d1c3*/
  v1[2] = 0x80000000; /*0x14d1ca*/
  v1[3] = a1; /*0x14d1d4*/
  v1[4] = 1; /*0x14d1d7*/
  v1[6] = 0; /*0x14d1de*/
  v1[7] = 0; /*0x14d1e5*/
  v1[8] = 0; /*0x14d1ec*/
  v1[9] = 0; /*0x14d1f3*/
  v1[10] = 0; /*0x14d1fa*/
  v1[11] = 0; /*0x14d201*/
  v1[12] = 0; /*0x14d208*/
  v1[13] = 0; /*0x14d20f*/
  v1[14] = 0; /*0x14d216*/
  v1[15] = 5; /*0x14d21d*/
  ipc_mqueue_init(v1 + 16); /*0x14d228*/
  v2[19] = 0; /*0x14d22d*/
  return v2; /*0x14d23a*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107440. */
void pqinit()
{
  int v0; // eax
  _DWORD *v1; // ebx

  v0 = zinit(136, 13600 * max_proc, 0, 0, aProcStructures); /*0x10745d*/
  proc_zone = v0; /*0x107462*/
  dword_1E56C0 = 0; /*0x107467*/
  freeproc = 0; /*0x107471*/
  if ( max_proc > 0 ) /*0x107485*/
  {
    dword_1E56C0 = 1; /*0x10748c*/
    v1 = (_DWORD *)zalloc(v0); /*0x10749c*/
  }
  else
  {
    v1 = nullptr; /*0x107487*/
  }
  bzero(v1, 0x88u); /*0x1074a7*/
  allproc = (unsigned int)v1; /*0x1074ac*/
  v1[2] = 0; /*0x1074b2*/
  v1[3] = &allproc; /*0x1074b9*/
  kernel_proc = (int)v1; /*0x1074c0*/
  zombproc = 0; /*0x1074c6*/
}

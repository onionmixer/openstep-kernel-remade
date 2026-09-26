/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e234. */
id autoconf()
{
  _DWORD *v0; // esi
  int (**v1)(); // ebx

  sub_17E2E0(); /*0x17e239*/
  IOInitGeneralFuncs(); /*0x17e23e*/
  volCheckInit(); /*0x17e243*/
  v0 = &pseudo_inits; /*0x17e248*/
  if ( off_1E4F84 ) /*0x17e254*/
  {
    v1 = &off_1E4F84; /*0x17e256*/
    do /*0x17e26c*/
    {
      ((void (__cdecl *)(_DWORD))*v1)(*v0); /*0x17e261*/
      v1 += 2; /*0x17e266*/
      v0 += 2; /*0x17e269*/
    }
    while ( *v1 ); /*0x17e26c*/
  }
  dword_1E7314 = +[Object alloc](aNxconditionloc, sel_alloc); /*0x17e284*/
  objc_msgSend(dword_1E7314, sel_initWith_, 0); /*0x17e293*/
  kernel_thread(IOTask_kern, (int)sub_17E4E8, 0); /*0x17e2a6*/
  objc_msgSend(dword_1E7314, sel_lockWhen_, 1); /*0x17e2be*/
  return objc_msgSend(dword_1E7314, sel_free); /*0x17e2d9*/
}

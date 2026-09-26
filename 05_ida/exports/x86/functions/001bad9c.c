/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bad9c. */
int __cdecl audio_reset_snd_dev_port(id a1, int a2)
{
  int v2; // ebx
  id v4; // eax
  int v5; // eax
  int v6; // eax
  id v7; // eax
  id v8; // eax
  id v9; // [esp-4h] [ebp-10h]
  int v10; // [esp+8h] [ebp-4h]

  v2 = IOHostPrivSelf(); /*0x1badac*/
  if ( !v2 )
  {
    IOLog((int)"Audio: cannot get kernel port (must run as root)\n");
    IOLog((int)"reset_snd_dev_port"); /*0x1badc1*/
  }
  if ( a2 != v2 ) /*0x1badcc*/
    return 0; /*0x1badce*/
  v4 = objc_msgSend(a1, sel__outputChannel); /*0x1bade7*/
  v9 = objc_msgSend(v4, sel_userSndPort); /*0x1badf8*/
  v5 = task_self(); /*0x1badf9*/
  if ( port_deallocate_EXTERNAL(v5, v9) )
    IOLog((int)"Audio: port_deallocate\n");
  v6 = task_self(); /*0x1bae1c*/
  if ( port_allocate_EXTERNAL(v6) )
    IOLog((int)"Audio: port_allocate");
  v7 = objc_msgSend(a1, sel__inputChannel); /*0x1bae4e*/
  objc_msgSend(v7, sel_setUserSndPort_); /*0x1bae57*/
  v8 = objc_msgSend(a1, sel__outputChannel); /*0x1bae6c*/
  objc_msgSend(v8, sel_setUserSndPort_); /*0x1bae75*/
  return v10; /*0x1bae7f*/
}

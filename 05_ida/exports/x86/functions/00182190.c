/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x182190. */
int __cdecl kern_dev_map_port_com(id a1, int a2, int a3)
{
  id v3; // eax
  id v4; // edi
  int i; // ebx
  id v6; // eax
  id v7; // eax
  int v8; // edx
  id v10; // [esp+Ch] [ebp-4h]

  v3 = objc_msgSend(a1, sel_deviceDescription); /*0x1821a4*/
  v4 = objc_msgSend(v3, sel_resourcesForKey_, aIOPorts_1); /*0x1821bb*/
  v10 = objc_msgSend(v4, sel_count); /*0x1821ca*/
  for ( i = 0; (int)v10 > i; ++i ) /*0x1821d4*/
  {
    v6 = objc_msgSend(v4, sel_objectAt_, i); /*0x1821e8*/
    v7 = objc_msgSend(v6, sel_range); /*0x1821f1*/
    task_map_io_ports(*(_DWORD *)(a2 + 12), v7, v8, a3); /*0x182203*/
  }
  return 0; /*0x182216*/
}

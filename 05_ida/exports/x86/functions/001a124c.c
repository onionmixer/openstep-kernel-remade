/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a124c. */
int __usercall PCmapBIOSRom@<eax>(int a1@<esi>, int a2, unsigned int a3, int a4)
{
  int v4; // esi
  int v6; // ebx
  unsigned int v7; // ecx
  unsigned int i; // ebx
  unsigned int v9; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+10h] [ebp-8h] BYREF
  unsigned int v11; // [esp+14h] [ebp-4h] BYREF

  if ( a4 ) /*0x1a1259*/
  {
    v11 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 20); /*0x1a1286*/
  }
  else
  {
    if ( copyin(a3, (unsigned int)&v11, 4) ) /*0x1a1265*/
      return 4; /*0x1a12ca*/
    v11 &= ~page_mask; /*0x1a1278*/
  }
  if ( !object_copyin(*(_DWORD *)(active_threads + 12), a2, 6, 0, (int)&v10) ) /*0x1a129e*/
    return 4; /*0x1a129e*/
  v4 = convert_port_to_task(v10); /*0x1a12b3*/
  port_release(v10); /*0x1a12b9*/
  if ( !v4 ) /*0x1a12c3*/
    return 4; /*0x1a12c3*/
  v6 = vm_map_find(*(_DWORD *)(v4 + 12), 0, 0, &v11, ~page_mask & (page_mask + 0x10000), a4); /*0x1a12f8*/
  if ( v6 ) /*0x1a12ff*/
  {
    task_deallocate(v4); /*0x1a1302*/
    return v6; /*0x1a1307*/
  }
  else if ( a4 && copyout((unsigned __int16 *)&v11, a3, 4) ) /*0x1a1320*/
  {
    task_deallocate(v4); /*0x1a132d*/
    return 4; /*0x1a1332*/
  }
  else
  {
    v7 = v11; /*0x1a1341*/
    v9 = ~page_mask & (v11 + page_mask + 0x10000); /*0x1a134f*/
    for ( i = ~page_mask & 0xF0000; v9 > v11; v7 = v11 ) /*0x1a135c*/
    {
      pmap_enter(*(_DWORD **)(*(_DWORD *)(v4 + 12) + 36), v7, i, 1, 1); /*0x1a136d*/
      v11 += page_size; /*0x1a137c*/
      i += page_size; /*0x1a137f*/
    }
    task_deallocate(v4); /*0x1a138c*/
    return 0; /*0x1a1391*/
  }
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x155ce8. */
int __cdecl port_names(
        ipc_space_t task,
        mach_port_name_array_t *names,
        mach_msg_type_number_t *namesCnt,
        mach_port_type_array_t *types,
        mach_msg_type_number_t *typesCnt)
{
  kern_return_t v5; // eax
  int v6; // ebx
  mach_msg_type_number_t v8; // esi
  int *v9; // ebx
  int *v10; // eax
  int v11; // [esp+Ch] [ebp-18h]
  int size; // [esp+14h] [ebp-10h]
  mach_msg_type_number_t v13; // [esp+18h] [ebp-Ch]
  vm_address_t address; // [esp+1Ch] [ebp-8h] BYREF
  int v15; // [esp+20h] [ebp-4h] BYREF

  v5 = mach_port_names(task, names, namesCnt, types, typesCnt); /*0x155d05*/
  v6 = v5; /*0x155d0a*/
  if ( v5 ) /*0x155d11*/
  {
    if ( v5 != 6 ) /*0x155e87*/
      return 4; /*0x155e89*/
  }
  else
  {
    v13 = *typesCnt; /*0x155d19*/
    address = (vm_address_t)*types; /*0x155d24*/
    size = ~page_mask & (page_mask + 4 * v13); /*0x155d33*/
    if ( vm_move(ipc_soft_map, address, ipc_kernel_map, size, 0, (int)&v15) ) /*0x155d52*/
    {
      kmem_free(ipc_soft_map, *types, ~page_mask & (page_mask + 4 * *typesCnt)); /*0x155d82*/
      kmem_free(ipc_soft_map, *names, ~page_mask & (page_mask + 4 * *namesCnt)); /*0x155dac*/
      return 6; /*0x155db6*/
    }
    vm_deallocate(ipc_soft_map, address, size); /*0x155dcb*/
    v8 = 0; /*0x155dd6*/
    if ( v13 ) /*0x155ddb*/
    {
      v9 = (int *)v15; /*0x155ddd*/
      do /*0x155de2*/
      {
        v10 = (int *)(*v9 & 0x1F0000); /*0x155de2*/
        if ( v10 == (int *)196608 ) /*0x155dec*/
          goto LABEL_17; /*0x155dec*/
        if ( (unsigned int)v10 > 0x30000 ) /*0x155dee*/
        {
          if ( v10 == (int *)0x80000 ) /*0x155e05*/
          {
            v11 = 9; /*0x155e30*/
            goto LABEL_20; /*0x155e37*/
          }
          if ( (unsigned int)v10 > 0x80000 ) /*0x155e07*/
          {
            if ( v10 != &dword_100000 ) /*0x155e19*/
LABEL_19:
              panic(aConvertPortTyp); /*0x155e3c*/
          }
          else if ( v10 != (int *)0x40000 ) /*0x155e0e*/
          {
            goto LABEL_19; /*0x155e0e*/
          }
        }
        else if ( v10 != (int *)0x10000 ) /*0x155df5*/
        {
          if ( v10 != (int *)0x20000 ) /*0x155dfc*/
            goto LABEL_19; /*0x155dfc*/
LABEL_17:
          v11 = 7; /*0x155e24*/
          goto LABEL_20; /*0x155e2b*/
        }
        v11 = 1; /*0x155e1b*/
LABEL_20:
        *v9++ = v11; /*0x155e49*/
        ++v8; /*0x155e51*/
      }
      while ( v13 > v8 ); /*0x155de2*/
    }
    v6 = vm_move(ipc_kernel_map, v15, ipc_soft_map, size, 1, (int)&address); /*0x155e57*/
    *types = (mach_port_type_array_t)address; /*0x155e80*/
  }
  return v6; /*0x155e93*/
}

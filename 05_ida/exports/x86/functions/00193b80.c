/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x193b80. */
int __cdecl startup(int a1)
{
  int v1; // eax
  int v2; // ebx
  int v3; // eax
  unsigned int v4; // ebx
  int v5; // esi
  int v6; // ecx
  int result; // eax
  mach_port_t v8; // [esp+0h] [ebp-24h]
  int v9; // [esp+Ch] [ebp-18h]
  unsigned int v10; // [esp+1Ch] [ebp-8h]
  int v11; // [esp+20h] [ebp-4h] BYREF

  cons_tp = (int)&cons; /*0x193b89*/
  LOWORD(cons._extra) = 3072; /*0x193b93*/
  kminit(); /*0x193b9c*/
  panic_init(v8); /*0x193ba1*/
  printf("NeXT Mach 4.2: Tue Jan 26 11:21:50 PST 1999; root(rcbuilder):Objects/mk-183.34.4.obj~2/RELEASE_I386\n");
  printf( /*0x193bed*/
    "physical memory = %d.%d%d megabytes.\n",
    (unsigned int)mem_size >> 20,
    (10 * (mem_size & 0xFFFFFu)) >> 20,
    (25 * (mem_size % 0x19999u)) >> 18);
  a1 = ~page_mask & (a1 + page_mask); /*0x193c04*/
  v1 = vm_object_allocate(0); /*0x193c16*/
  vm_map_find(kernel_map, v1, 0, (unsigned int *)&a1, 0x800000, 1); /*0x193c27*/
  vm_map_remove((_DWORD *)kernel_map, a1, a1 + 0x800000); /*0x193c46*/
  buffers = a1; /*0x193c4e*/
  v10 = bufpages % nbuf; /*0x193c70*/
  v9 = bufpages / nbuf; /*0x193c73*/
  v2 = (~page_mask & (page_mask + (nbuf << 13) + a1)) - a1; /*0x193c89*/
  buffer_map = kmem_suballoc(kernel_map, &a1, &v11, v2, 1); /*0x193ca4*/
  v3 = vm_object_allocate(v2); /*0x193cb7*/
  vm_map_find(buffer_map, v3, 0, (unsigned int *)&a1, v2, 0); /*0x193cc9*/
  v4 = 0; /*0x193cce*/
  if ( nbuf ) /*0x193cd9*/
  {
    v5 = 0; /*0x193ce2*/
    do /*0x193d26*/
    {
      if ( v10 <= v4 ) /*0x193ce7*/
        v6 = v9; /*0x193cf0*/
      else
        v6 = v9 + 1; /*0x193ce9*/
      vm_map_pageable(buffer_map, v5 + buffers, v5 + buffers + page_size * v6, 0); /*0x193d11*/
      v5 += 0x2000; /*0x193d19*/
      ++v4; /*0x193d1f*/
    }
    while ( nbuf > v4 ); /*0x193d26*/
  }
  printf( /*0x193da0*/
    "using %d buffers containing %d.%d%d megabytes of memory\n",
    nbuf,
    (bufpages << page_shift) / 0x100000,
    10 * ((bufpages << page_shift) % 0x100000) / 0x100000,
    100 * ((bufpages << page_shift) % 104857) / 0x100000);
  printf( /*0x193e1a*/
    "available memory = %d.%d%d megabytes. vm_page_free_count = %x\n",
    (vm_page_free_count << page_shift) / 0x100000,
    10 * ((vm_page_free_count << page_shift) % 0x100000) / 0x100000,
    100 * ((vm_page_free_count << page_shift) % 104857) / 0x100000,
    vm_page_free_count);
  result = kmem_suballoc(kernel_map, &mbutl, embutl, nmbclusters << 10, 0); /*0x193e3f*/
  mb_map = result; /*0x193e46*/
  return result; /*0x193e4f*/
}

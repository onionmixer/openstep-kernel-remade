/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x105840. */
int load_init_program()
{
  int v0; // esi
  int result; // eax
  vm_address_t v2; // eax
  vm_address_t v3; // eax
  int v4; // ebx
  const char *v5; // [esp+0h] [ebp-18h]
  char *const *v6; // [esp+4h] [ebp-14h]
  vm_address_t address; // [esp+8h] [ebp-10h] BYREF
  _DWORD v8[3]; // [esp+Ch] [ebp-Ch] BYREF

  v0 = 0; /*0x105848*/
  do /*0x1059b0*/
  {
    if ( (boothowto & 0x10) != 0 ) /*0x105853*/
    {
      printf("init program? "); /*0x10585a*/
      gets(init_program_name); /*0x105869*/
    }
    if ( v0 && (boothowto & 0x10) == 0 && init_attempts == 1 ) /*0x105885*/
    {
      printf("Load of %s, errno %d, trying %s\n", init_program_name, v0, aEtcInit); /*0x105897*/
      v0 = 0; /*0x10589c*/
      bcopy(aEtcInit, init_program_name, 0xAu); /*0x1058aa*/
    }
    ++init_attempts; /*0x1058b2*/
    if ( v0 ) /*0x1058ba*/
    {
      result = printf("Load of %s failed, errno %d\n", init_program_name, v0); /*0x1058c7*/
      v0 = 0; /*0x1058cc*/
      LOBYTE(boothowto) = boothowto | 0x10; /*0x1058ce*/
    }
    else
    {
      address = 0; /*0x1058e0*/
      vm_allocate(*(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12), &address, page_size, 1); /*0x105900*/
      if ( !address ) /*0x10590c*/
        address = 1; /*0x10590e*/
      copyout(init_program_name, address, 129); /*0x105923*/
      v8[0] = address; /*0x10592b*/
      v2 = address + 143; /*0x105931*/
      LOBYTE(v2) = (address - 113) & 0xF0; /*0x105936*/
      address = v2; /*0x105938*/
      copyout(init_args, v2, 128); /*0x105946*/
      v8[1] = address; /*0x10594e*/
      v3 = address + 143; /*0x105954*/
      LOBYTE(v3) = (address - 113) & 0xF0; /*0x105959*/
      address = v3; /*0x10595b*/
      v8[2] = 0; /*0x10595e*/
      copyout(v8, v3, 12); /*0x10596c*/
      init_exec_args = v8[0]; /*0x105974*/
      dword_1E90C4 = address; /*0x10597d*/
      dword_1E90C8 = 0; /*0x105983*/
      v4 = *(_DWORD *)(dword_1E875C + 36); /*0x105992*/
      *(_DWORD *)(dword_1E875C + 36) = &init_exec_args; /*0x105995*/
      v0 = execve(v5, v6, (char *const *)address); /*0x1059a4*/
      result = dword_1E875C; /*0x1059a6*/
      *(_DWORD *)(dword_1E875C + 36) = v4; /*0x1059ab*/
    }
  }
  while ( v0 ); /*0x1059b0*/
  return result; /*0x1059b9*/
}

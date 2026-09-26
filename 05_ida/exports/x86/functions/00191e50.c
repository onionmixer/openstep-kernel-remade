/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x191e50. */
void __cdecl user_trap(int a1)
{
  mach_msg_type_number_t *v1; // esi
  unsigned __int32 v2; // eax
  mach_msg_type_number_t v3; // ebx
  int v4; // ecx
  exception_data_type_t *code; // [esp+Ch] [ebp-1Ch]
  char codea; // [esp+Ch] [ebp-1Ch]
  int v7; // [esp+10h] [ebp-18h]
  exception_data_type_t *v8; // [esp+14h] [ebp-14h]
  int v9; // [esp+18h] [ebp-10h]
  int v10; // [esp+1Ch] [ebp-Ch]
  int v11; // [esp+20h] [ebp-8h]
  thread_act_t v12; // [esp+24h] [ebp-4h]

  v1 = (mach_msg_type_number_t *)(a1 + 52); /*0x191e5c*/
  v12 = active_threads; /*0x191e66*/
  code = *(exception_data_type_t **)(a1 + 48); /*0x191e6f*/
  v11 = *(_DWORD *)active_u; /*0x191e7a*/
  if ( *(_DWORD *)active_u ) /*0x191e7a*/
  {
    v9 = *(_DWORD *)(active_u + 376); /*0x191e87*/
    v10 = *(_DWORD *)(active_u + 380); /*0x191e90*/
  }
  switch ( (unsigned int)code ) /*0x191ea0*/
  {
    case 0u: /*0x191ea0*/
      exception(3, nullptr, 0); /*0x191efc*/
      break; /*0x191efc*/
    case 1u: /*0x191ea0*/
      exception(6, (exception_data_t)1, 0); /*0x191f10*/
      break; /*0x191f10*/
    case 3u: /*0x191ea0*/
      exception(6, (exception_data_t)3, 0); /*0x191f24*/
      break; /*0x191f24*/
    case 4u: /*0x191ea0*/
      exception(5, (exception_data_t)4, 0); /*0x191f38*/
      break; /*0x191f38*/
    case 5u: /*0x191ea0*/
      exception(5, (exception_data_t)5, 0); /*0x191f4c*/
      break; /*0x191f4c*/
    case 6u: /*0x191ea0*/
      exception(2, (exception_data_t)6, 0); /*0x191f60*/
      break; /*0x191f60*/
    case 7u: /*0x191ea0*/
      fp_noextension(); /*0x191f6c*/
      break; /*0x191f74*/
    case 0xBu: /*0x191ea0*/
      exception(2, (exception_data_t)0xB, *v1); /*0x191f8a*/
      break; /*0x191f8a*/
    case 0xCu: /*0x191ea0*/
      exception(2, (exception_data_t)0xC, *v1); /*0x191f9e*/
      break; /*0x191f9e*/
    case 0xDu: /*0x191ea0*/
      exception(2, (exception_data_t)0xD, *v1); /*0x191fb2*/
      break; /*0x191fb2*/
    case 0xEu: /*0x191ea0*/
      v2 = __readcr2(); /*0x191fb8*/
      v3 = v2; /*0x191fbe*/
      codea = *(_BYTE *)(dword_1E875C + 104); /*0x191fcb*/
      *(_BYTE *)(dword_1E875C + 104) = 0; /*0x191fd4*/
      v4 = 1; /*0x191fdc*/
      if ( (*(_BYTE *)v1 & 2) != 0 ) /*0x191fe4*/
        v4 = 3; /*0x191fe6*/
      v8 = (exception_data_type_t *)vm_fault(*(_DWORD *)(*(_DWORD *)(v12 + 12) + 12), v2 & ~page_mask, v4, 0, nullptr); /*0x192005*/
      *(_BYTE *)(dword_1E875C + 104) = codea; /*0x192011*/
      if ( v8 ) /*0x19201b*/
        exception(1, v8, v3); /*0x192028*/
      break; /*0x192028*/
    case 0x10u: /*0x191ea0*/
      fp_extension_fault(); /*0x192030*/
      break; /*0x192038*/
    case 0x11u: /*0x191ea0*/
      exception(5, (exception_data_t)0x11, 0); /*0x192048*/
      break; /*0x192048*/
    default:
      exception(2, code, 0); /*0x19205d*/
      break; /*0x19205d*/
  }
  if ( v11 ) /*0x192069*/
  {
    if ( *(_DWORD *)(active_u + 604) ) /*0x192071*/
    {
      v7 = (*(_DWORD *)(active_u + 380) - v10) / 1000 + 1000 * (*(_DWORD *)(active_u + 376) - v9); /*0x1920b1*/
      if ( v7 / (tick / 1000) ) /*0x1920c9*/
        addupc(*(_DWORD *)(a1 + 56), active_u + 584, v7 / (tick / 1000)); /*0x1920db*/
    }
  }
  thread_exception_return(); /*0x1920e3*/
}

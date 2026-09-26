/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1920f4. */
int __usercall kernel_trap@<eax>(char a1@<bl>, int a2)
{
  mach_msg_type_number_t *v2; // esi
  int v3; // edi
  int result; // eax
  unsigned __int32 v5; // ecx
  int v6; // eax
  unsigned int v7; // ebx
  int v8; // eax
  int v9; // [esp+Ch] [ebp-10h]
  exception_data_type_t *code; // [esp+10h] [ebp-Ch]
  mach_msg_type_number_t codeCnt; // [esp+14h] [ebp-8h]
  exception_data_type_t *v12; // [esp+18h] [ebp-4h]

  v2 = (mach_msg_type_number_t *)(a2 + 52); /*0x192100*/
  v3 = 0; /*0x192103*/
  v12 = *(exception_data_type_t **)(a2 + 48); /*0x19210b*/
  result = (int)v12 - 1; /*0x192110*/
  switch ( (unsigned int)v12 ) /*0x19211a*/
  {
    case 1u: /*0x19211a*/
    case 3u: /*0x19211a*/
      return sub_192438(a2); /*0x19217d*/
    case 7u: /*0x19211a*/
      return result;
    case 0xAu: /*0x19211a*/
      if ( (*(_BYTE *)(a2 + 65) & 0x40) != 0 ) /*0x19227c*/
      {
        sub_1924E0(a2); /*0x192282*/
        thread_exception_return(); /*0x192287*/
      }
      goto LABEL_21; /*0x192287*/
    case 0xBu: /*0x19211a*/
    case 0xCu: /*0x19211a*/
    case 0xDu: /*0x19211a*/
      if ( (*(_BYTE *)v2 & 6) == 4 ) /*0x192252*/
      {
        sub_1924E0(a2); /*0x192258*/
        v3 = *v2; /*0x192260*/
        exception_from_kernel(2, v12, *v2); /*0x192269*/
        thread_exception_return(); /*0x19226e*/
      }
      goto LABEL_21; /*0x192276*/
    case 0xEu: /*0x19211a*/
      v5 = __readcr2(); /*0x192184*/
      codeCnt = v5; /*0x192187*/
      if ( active_threads ) /*0x192191*/
      {
        a1 = *(_BYTE *)(dword_1E875C + 104); /*0x192198*/
        *(_BYTE *)(dword_1E875C + 104) = 0; /*0x19219c*/
      }
      if ( v5 <= 0xBFFFFFFF ) /*0x1921a7*/
      {
        v6 = 1; /*0x1921c0*/
        if ( (*(_BYTE *)v2 & 2) != 0 ) /*0x1921c8*/
          v6 = 3; /*0x1921ca*/
        result = vm_fault(*(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12), v5 & ~page_mask, v6, 0, nullptr); /*0x1921e7*/
        code = (exception_data_type_t *)result; /*0x1921ec*/
      }
      else
      {
        result = sub_1923E0(v5, v2); /*0x1921ae*/
        code = (exception_data_type_t *)result; /*0x1921b3*/
      }
      if ( active_threads ) /*0x1921f9*/
      {
        result = dword_1E875C; /*0x1921fb*/
        *(_BYTE *)(dword_1E875C + 104) = a1; /*0x192200*/
      }
      if ( !code ) /*0x192207*/
        return result; /*0x192207*/
      result = sub_1924A0(v2); /*0x19220e*/
      if ( result ) /*0x192218*/
        return result; /*0x192218*/
      if ( codeCnt <= 0xBFFFFFFF ) /*0x192225*/
      {
        sub_1924E0(a2); /*0x19222b*/
        v3 = codeCnt; /*0x192230*/
        exception_from_kernel(1, code, codeCnt); /*0x19223a*/
        thread_exception_return(); /*0x19223f*/
      }
LABEL_21:
      result = sub_1924A0(v2); /*0x19228f*/
      if ( !result ) /*0x19229a*/
      {
        DoAlert(aKernelTrap, &unk_1E280C); /*0x1922aa*/
        printf("unexpected kernel trap %x eip %x\n", v12, *(_DWORD *)(a2 + 56)); /*0x1922bc*/
        switch ( (unsigned int)v12 ) /*0x1922d1*/
        {
          case 0u: /*0x1922d1*/
            v7 = 3; /*0x192320*/
            v8 = 0; /*0x192325*/
            break; /*0x192327*/
          case 4u: /*0x1922d1*/
            v7 = 5; /*0x19232c*/
            v8 = 4; /*0x192331*/
            break; /*0x192336*/
          case 5u: /*0x1922d1*/
            v7 = 3; /*0x192338*/
            v8 = 5; /*0x19233d*/
            break; /*0x192342*/
          case 6u: /*0x1922d1*/
            v7 = 2; /*0x192344*/
            v8 = 6; /*0x192349*/
            break; /*0x19234e*/
          case 0xBu: /*0x1922d1*/
            v7 = 2; /*0x192350*/
            v8 = 11; /*0x192355*/
            v3 = *v2; /*0x19235a*/
            break; /*0x19235c*/
          case 0xCu: /*0x1922d1*/
            v7 = 2; /*0x192360*/
            v8 = 12; /*0x192365*/
            v3 = *v2; /*0x19236a*/
            break; /*0x19236c*/
          case 0xDu: /*0x1922d1*/
            v7 = 2; /*0x192370*/
            v8 = 13; /*0x192375*/
            v3 = *v2; /*0x19237a*/
            break; /*0x19237c*/
          case 0xEu: /*0x1922d1*/
            v7 = 1; /*0x192380*/
            v8 = (int)code; /*0x192385*/
            v3 = codeCnt; /*0x192388*/
            break; /*0x19238b*/
          case 0x11u: /*0x1922d1*/
            v7 = 5; /*0x192390*/
            v8 = 17; /*0x192395*/
            break; /*0x19239a*/
          default:
            v7 = 2; /*0x19239c*/
            v8 = (int)v12; /*0x1923a1*/
            break; /*0x1923a1*/
        }
        v9 = v8; /*0x1923ad*/
        _i386_backtrace(*(_DWORD *)(a2 + 24), 4); /*0x1923b0*/
        kdp_raise_exception(v7, v9, v3, a2); /*0x1923bf*/
        DoRestore(); /*0x1923c4*/
        panic(aContinuedAfter); /*0x1923ce*/
      }
      return result;
    case 0x10u: /*0x19211a*/
      return fp_kernel_extension_fault(); /*0x19216d*/
    default:
      goto LABEL_21;
  }
}

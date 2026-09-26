/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c0c0. */
int __cdecl task_by_pid(int a1)
{
  int v1; // esi
  int v2; // ebx
  int v3; // eax
  int v4; // eax
  int v5; // edx
  int v7; // [esp+8h] [ebp-8h] BYREF
  int v8; // [esp+Ch] [ebp-4h]

  v1 = *(_DWORD *)(active_threads + 12); /*0x17c0d0*/
  v7 = 0; /*0x17c0d3*/
  v2 = pfind(a1); /*0x17c0e0*/
  if ( v2 /*0x17c107*/
    && (v3 = *(_DWORD *)(v1 + 60)) != 0
    && (*(_WORD *)(v2 + 44) == *(_WORD *)(v3 + 44) || suser())
    && *(_BYTE *)(v2 + 19) != 5 )
  {
    if ( *(_DWORD *)(v2 + 104) ) /*0x17c109*/
      task_reference(*(_DWORD *)(v2 + 104)); /*0x17c111*/
    v8 = *(_DWORD *)(v2 + 104); /*0x17c11c*/
    if ( suser() ) /*0x17c11f*/
    {
      v4 = *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 60); /*0x17c130*/
      if ( v4 ) /*0x17c135*/
        *(_BYTE *)(v4 + 22) |= 1u; /*0x17c137*/
    }
    v5 = convert_task_to_port(v8); /*0x17c155*/
    v7 = v5; /*0x17c157*/
    if ( v5 ) /*0x17c15f*/
      object_copyout(v1, v5, 6, &v7); /*0x17c169*/
  }
  else
  {
    v8 = 0; /*0x17c140*/
  }
  return v7; /*0x17c174*/
}

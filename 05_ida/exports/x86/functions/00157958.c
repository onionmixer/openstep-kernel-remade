/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157958. */
kern_return_t __cdecl host_processors(
        host_priv_t host_priv,
        processor_array_t *out_processor_list,
        mach_msg_type_number_t *out_processor_listCnt)
{
  mach_msg_type_number_t v4; // edi
  int v5; // ebx
  int v6; // eax
  processor_t *v7; // eax
  int v8; // ebx
  mach_msg_type_number_t v9; // ebx
  processor_t *v10; // esi
  int v11; // [esp+Ch] [ebp-8h]
  processor_t *v12; // [esp+10h] [ebp-4h]

  if ( !host_priv ) /*0x157968*/
    return 4; /*0x15796a*/
  v4 = 0; /*0x157974*/
  v5 = 0; /*0x157976*/
  v6 = 0; /*0x157978*/
  do /*0x15798c*/
  {
    if ( machine_slot[v6] ) /*0x15797c*/
      ++v4; /*0x157985*/
    v6 += 8; /*0x157986*/
    ++v5; /*0x157989*/
  }
  while ( v5 <= 0 ); /*0x15798c*/
  if ( !v4 ) /*0x157990*/
    panic(aHostProcessors); /*0x157997*/
  v12 = (processor_t *)kalloc(4 * v4); /*0x1579ac*/
  if ( !v12 ) /*0x1579b4*/
    return 6; /*0x1579b6*/
  v7 = v12; /*0x1579c0*/
  v8 = 0; /*0x1579c3*/
  v11 = 0; /*0x1579c5*/
  do /*0x1579eb*/
  {
    if ( machine_slot[v11] ) /*0x1579cf*/
      *v7++ = processor_ptr[v8]; /*0x1579df*/
    v11 += 8; /*0x1579e4*/
    ++v8; /*0x1579e8*/
  }
  while ( v8 <= 0 ); /*0x1579eb*/
  *out_processor_listCnt = v4; /*0x1579ed*/
  *out_processor_list = v12; /*0x1579f5*/
  v9 = 0; /*0x1579fa*/
  v10 = v12; /*0x157a00*/
  do /*0x157a17*/
  {
    *v10 = convert_processor_to_port(*v10); /*0x157a0c*/
    ++v10; /*0x157a11*/
    ++v9; /*0x157a14*/
  }
  while ( v9 < v4 ); /*0x157a17*/
  return 0; /*0x157a1e*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca754. */
char __cdecl -[Protocol conformsTo:](Protocol *self, SEL a2, id a3)
{
  __int32 v4; // ebx
  objc_protocol_list *protocol_list; // edx
  const char **v6; // [esp+Ch] [ebp-4h]

  if ( a3 ) /*0x1ca762*/
  {
    if ( !strcmp(*((const char **)a3 + 1), self->protocol_name) ) /*0x1ca76f*/
      return 1; /*0x1ca780*/
    if ( self->protocol_list ) /*0x1ca787*/
    {
      v4 = 0; /*0x1ca78d*/
      protocol_list = self->protocol_list; /*0x1ca792*/
      if ( protocol_list->count > 0 ) /*0x1ca797*/
      {
        while ( 1 ) /*0x1ca7a0*/
        {
          v6 = (const char **)protocol_list->list[v4]; /*0x1ca7a0*/
          if ( !strcmp(*((const char **)a3 + 1), v6[1]) || (unsigned __int8)objc_msgSend(v6, sel_conformsTo_, a3) ) /*0x1ca7c3*/
            break; /*0x1ca7c3*/
          ++v4; /*0x1ca7cf*/
          protocol_list = self->protocol_list; /*0x1ca7d3*/
          if ( protocol_list->count <= v4 ) /*0x1ca7d9*/
            return 0; /*0x1ca7d9*/
        }
        return 1; /*0x1ca7cd*/
      }
    }
  }
  return 0; /*0x1ca7e0*/
}

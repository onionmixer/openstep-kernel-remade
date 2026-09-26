/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca1e0. */
objc_method_description *__cdecl -[Object descriptionForMethod:](Object *self, SEL a2, SEL a3)
{
  Class i; // edi
  objc_protocol_list *j; // esi
  Protocol *v5; // eax
  objc_method_description *result; // eax
  Class isa; // edi
  objc_method_list **methodLists; // ecx
  int v9; // edx
  __int32 k; // [esp+Ch] [ebp-4h]

  for ( i = self->isa; i; i = i->super_class ) /*0x1ca1ec*/
  {
    if ( i->isa->version > 2 ) /*0x1ca1fa*/
    {
      for ( j = i->protocols; j; j = j->next ) /*0x1ca201*/
      {
        for ( k = 0; j->count > k; ++k ) /*0x1ca204*/
        {
          v5 = j->list[k]; /*0x1ca213*/
          if ( (i->info & 2) != 0 ) /*0x1ca21b*/
            result = -[Protocol descriptionForClassMethod:](v5, sel_descriptionForClassMethod_, a3); /*0x1ca227*/
          else
            result = -[Protocol descriptionForInstanceMethod:](v5, sel_descriptionForInstanceMethod_, a3); /*0x1ca238*/
          if ( result ) /*0x1ca242*/
            return result; /*0x1ca242*/
        }
        if ( i->isa->version <= 4 ) /*0x1ca255*/
          break; /*0x1ca255*/
      }
    }
  }
  isa = self->isa; /*0x1ca267*/
  if ( !self->isa ) /*0x1ca267*/
    return nullptr; /*0x1ca2ab*/
  while ( 1 ) /*0x1ca270*/
  {
    methodLists = isa->methodLists; /*0x1ca270*/
    if ( methodLists ) /*0x1ca275*/
      break; /*0x1ca275*/
LABEL_21:
    isa = isa->super_class; /*0x1ca2a4*/
    if ( !isa ) /*0x1ca2a9*/
      return nullptr; /*0x1ca2a9*/
  }
  while ( 1 ) /*0x1ca278*/
  {
    v9 = 0; /*0x1ca278*/
    if ( (int)methodLists[1] > 0 ) /*0x1ca27d*/
      break; /*0x1ca27d*/
LABEL_20:
    methodLists = (objc_method_list **)*methodLists; /*0x1ca29e*/
    if ( !methodLists ) /*0x1ca2a2*/
      goto LABEL_21; /*0x1ca2a2*/
  }
  while ( methodLists[3 * v9 + 2] != (objc_method_list *)a3 ) /*0x1ca28d*/
  {
    if ( (int)methodLists[1] <= ++v9 ) /*0x1ca29c*/
      goto LABEL_20; /*0x1ca29c*/
  }
  return (objc_method_description *)&methodLists[3 * v9 + 2]; /*0x1ca2b0*/
}

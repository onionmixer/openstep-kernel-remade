/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ccfbc. */
Class __cdecl class_poseAs(Class imposter, Class original)
{
  void *v3; // edx
  objc_class *v4; // edx
  char *v5; // eax
  uint32_t v6; // ecx
  uint32_t v7; // edx
  NXHashTable *table; // [esp+Ch] [ebp-124h]
  id v9; // [esp+10h] [ebp-120h]
  unsigned int i; // [esp+10h] [ebp-120h]
  int v11; // [esp+14h] [ebp-11Ch]
  unsigned int v12; // [esp+18h] [ebp-118h]
  char *__dst; // [esp+1Ch] [ebp-114h]
  uint32_t size; // [esp+20h] [ebp-110h] BYREF
  void *data; // [esp+24h] [ebp-10Ch] BYREF
  NXHashState state; // [esp+28h] [ebp-108h] BYREF
  char __s1[256]; // [esp+30h] [ebp-100h] BYREF

  v12 = _objc_headerCount(); /*0x1ccfd0*/
  v11 = _objc_headerVector(0); /*0x1ccfdd*/
  if ( original != imposter )
  {
    if ( imposter->super_class != original )
      return (Class)-[objc_class error:](
                      imposter,
                      sel_error_,
                      "[%s poseAs:%s]: target not immediate superclass",
                      imposter->name,
                      original->name);
    if ( imposter->ivars )
      return (Class)-[objc_class error:](
                      imposter,
                      sel_error_,
                      "[%s poseAs:%s]: %s defines new instance variables",
                      imposter->name,
                      original->name,
                      imposter->name);
    strcpy(__s1, "_%"); /*0x1cd04b*/
    strcat(__s1, original->name); /*0x1cd072*/
    __dst = (char *)sub_1CD3B0(strlen(__s1) + 1); /*0x1cd093*/
    strcpy(__dst, __s1); /*0x1cd0a1*/
    sub_1CCF4C((int)original); /*0x1cd0aa*/
    sub_1CCF4C((int)imposter); /*0x1cd0b0*/
    table = (NXHashTable *)objc_getClasses(); /*0x1cd0ba*/
    NXHashRemove(table, imposter); /*0x1cd0c8*/
    NXHashRemove(table, original); /*0x1cd0d2*/
    v9 = object_copy(imposter, 0); /*0x1cd0df*/
    NXHashInsert(table, v9); /*0x1cd0e7*/
    LOBYTE(imposter->info) |= 8u; /*0x1cd0ec*/
    LOBYTE(imposter->isa->info) |= 8u; /*0x1cd0f2*/
    imposter->name = original->name; /*0x1cd0f9*/
    imposter->isa->name = original->isa->name; /*0x1cd106*/
    imposter->version = original->version; /*0x1cd10c*/
    state = NXInitHashState(table); /*0x1cd11b*/
LABEL_7:
    while ( NXNextHashState(table, &state, &data) ) /*0x1cd14b*/
    {
      if ( data && data != imposter ) /*0x1cd15c*/
      {
        while ( data != v9 ) /*0x1cd16c*/
        {
          v3 = data; /*0x1cd16e*/
          if ( *((Class *)data + 1) == original ) /*0x1cd17a*/
          {
            *((_DWORD *)data + 1) = imposter; /*0x1cd17c*/
            *(_DWORD *)(*(_DWORD *)v3 + 4) = imposter->isa; /*0x1cd183*/
            goto LABEL_7; /*0x1cd186*/
          }
          v4 = *((objc_class **)data + 1); /*0x1cd18e*/
          data = v4; /*0x1cd191*/
          if ( !v4 || v4 == imposter ) /*0x1cd19d*/
            goto LABEL_7; /*0x1cd19d*/
        }
      }
    }
    for ( i = 0; i < v12; ++i ) /*0x1cd1a4*/
    {
      v5 = getsectdatafromheader(*(const mach_header **)(v11 + 24 * i), "__OBJC", "__cls_refs", &size); /*0x1cd1d4*/
      if ( v5 ) /*0x1cd1de*/
      {
        v6 = 0; /*0x1cd1e0*/
        if ( size >> 2 ) /*0x1cd1e8*/
        {
          v7 = size >> 2; /*0x1cd1f5*/
          do /*0x1cd206*/
          {
            if ( *(Class *)&v5[4 * v6] == original ) /*0x1cd1fe*/
              *(_DWORD *)&v5[4 * v6] = imposter; /*0x1cd200*/
            ++v6; /*0x1cd203*/
          }
          while ( v6 < v7 ); /*0x1cd206*/
        }
      }
    }
    original->name = __dst + 1; /*0x1cd226*/
    original->isa->name = __dst; /*0x1cd231*/
    NXHashInsert(table, imposter); /*0x1cd23c*/
    NXHashInsert(table, original); /*0x1cd246*/
  }
  return imposter; /*0x1cd253*/
}

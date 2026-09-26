/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cea70. */
id objc_msgSendSuper(objc_super *a1, SEL a2, ...)
{
  objc_cache *cache; // eax
  Method *buckets; // edi
  unsigned int mask; // esi
  SEL i; // edx
  int v6; // edx
  Method v7; // eax
  void (__cdecl __noreturn *v10)(void *, SEL); // eax
  __int32 v11; // ecx
  objc_cache *v12; // eax
  Method *v13; // edi
  unsigned int v14; // esi
  SEL j; // edx
  int v16; // edx
  Method v17; // eax
  id (__cdecl *method_imp)(objc_super *); // eax
  void (__cdecl __noreturn *v20)(void *, SEL); // eax
  objc_super *receiver; // [esp+4h] [ebp+4h]
  objc_super *v22; // [esp+4h] [ebp+4h]
  objc_super *v23; // [esp+4h] [ebp+4h]

  if ( _objc_multithread_mask ) /*0x1cea77*/
  {
    cache = a1->super_class->cache; /*0x1cea89*/
    buckets = cache->buckets; /*0x1cea8d*/
    mask = cache->mask; /*0x1cea90*/
    for ( i = a2; ; i = (SEL)(v6 + 1) ) /*0x1cea93*/
    {
      v6 = mask & (unsigned int)i; /*0x1cea95*/
      v7 = buckets[v6]; /*0x1cea97*/
      if ( !v7 ) /*0x1cea9c*/
        break; /*0x1cea9c*/
      if ( a2 == v7->method_name ) /*0x1ceaa1*/
        return ((id (__cdecl *)(id))v7->method_imp)(a1->receiver); /*0x1ceab3*/
    }
    receiver = (objc_super *)a1->receiver; /*0x1cead7*/
    v10 = _class_lookupMethodAndLoadCache((int)a1->super_class, (int)a2); /*0x1ceae2*/
    return ((id (__cdecl *)(objc_super *))v10)(receiver); /*0x1ceaea*/
  }
  else
  {
    v11 = 1; /*0x1ceb00*/
    do /*0x1ceb10*/
      v11 = _InterlockedExchange(&messageLock, v11); /*0x1ceb0b*/
    while ( v11 ); /*0x1ceb10*/
    v12 = a1->super_class->cache; /*0x1ceb1e*/
    v13 = v12->buckets; /*0x1ceb22*/
    v14 = v12->mask; /*0x1ceb25*/
    for ( j = a2; ; j = (SEL)(v16 + 1) ) /*0x1ceb28*/
    {
      v16 = v14 & (unsigned int)j; /*0x1ceb2a*/
      v17 = v13[v16]; /*0x1ceb2c*/
      if ( !v17 ) /*0x1ceb31*/
        break; /*0x1ceb31*/
      if ( a2 == v17->method_name ) /*0x1ceb36*/
      {
        method_imp = (id (__cdecl *)(objc_super *))v17->method_imp; /*0x1ceb3c*/
        v22 = (objc_super *)a1->receiver; /*0x1ceb42*/
        messageLock = 0; /*0x1ceb48*/
        return method_imp(v22); /*0x1ceb52*/
      }
    }
    v23 = (objc_super *)a1->receiver; /*0x1ceb77*/
    v20 = _class_lookupMethodAndLoadCache((int)a1->super_class, (int)a2); /*0x1ceb82*/
    messageLock = 0; /*0x1ceb8a*/
    return ((id (__cdecl *)(objc_super *))v20)(v23); /*0x1ceb94*/
  }
}

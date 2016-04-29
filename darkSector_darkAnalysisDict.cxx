// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME darkSector_darkAnalysisDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "darkSectorDecayProbability.h"
#include "darkSectorEvent.h"
#include "darkSectorFinalState.h"
#include "darkSectorMeson.h"
#include "darkSectorTrack.h"
#include "darkSectorUtilities.h"
#include "darkSectorVB.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_darkSectorTrack(void *p = 0);
   static void *newArray_darkSectorTrack(Long_t size, void *p);
   static void delete_darkSectorTrack(void *p);
   static void deleteArray_darkSectorTrack(void *p);
   static void destruct_darkSectorTrack(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::darkSectorTrack*)
   {
      ::darkSectorTrack *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::darkSectorTrack >(0);
      static ::ROOT::TGenericClassInfo 
         instance("darkSectorTrack", ::darkSectorTrack::Class_Version(), "darkSectorTrack.h", 8,
                  typeid(::darkSectorTrack), DefineBehavior(ptr, ptr),
                  &::darkSectorTrack::Dictionary, isa_proxy, 4,
                  sizeof(::darkSectorTrack) );
      instance.SetNew(&new_darkSectorTrack);
      instance.SetNewArray(&newArray_darkSectorTrack);
      instance.SetDelete(&delete_darkSectorTrack);
      instance.SetDeleteArray(&deleteArray_darkSectorTrack);
      instance.SetDestructor(&destruct_darkSectorTrack);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::darkSectorTrack*)
   {
      return GenerateInitInstanceLocal((::darkSectorTrack*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::darkSectorTrack*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_darkSectorEvent(void *p = 0);
   static void *newArray_darkSectorEvent(Long_t size, void *p);
   static void delete_darkSectorEvent(void *p);
   static void deleteArray_darkSectorEvent(void *p);
   static void destruct_darkSectorEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::darkSectorEvent*)
   {
      ::darkSectorEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::darkSectorEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("darkSectorEvent", ::darkSectorEvent::Class_Version(), "darkSectorEvent.h", 11,
                  typeid(::darkSectorEvent), DefineBehavior(ptr, ptr),
                  &::darkSectorEvent::Dictionary, isa_proxy, 4,
                  sizeof(::darkSectorEvent) );
      instance.SetNew(&new_darkSectorEvent);
      instance.SetNewArray(&newArray_darkSectorEvent);
      instance.SetDelete(&delete_darkSectorEvent);
      instance.SetDeleteArray(&deleteArray_darkSectorEvent);
      instance.SetDestructor(&destruct_darkSectorEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::darkSectorEvent*)
   {
      return GenerateInitInstanceLocal((::darkSectorEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::darkSectorEvent*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_darkSectorUtilities(void *p = 0);
   static void *newArray_darkSectorUtilities(Long_t size, void *p);
   static void delete_darkSectorUtilities(void *p);
   static void deleteArray_darkSectorUtilities(void *p);
   static void destruct_darkSectorUtilities(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::darkSectorUtilities*)
   {
      ::darkSectorUtilities *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::darkSectorUtilities >(0);
      static ::ROOT::TGenericClassInfo 
         instance("darkSectorUtilities", ::darkSectorUtilities::Class_Version(), "darkSectorUtilities.h", 15,
                  typeid(::darkSectorUtilities), DefineBehavior(ptr, ptr),
                  &::darkSectorUtilities::Dictionary, isa_proxy, 4,
                  sizeof(::darkSectorUtilities) );
      instance.SetNew(&new_darkSectorUtilities);
      instance.SetNewArray(&newArray_darkSectorUtilities);
      instance.SetDelete(&delete_darkSectorUtilities);
      instance.SetDeleteArray(&deleteArray_darkSectorUtilities);
      instance.SetDestructor(&destruct_darkSectorUtilities);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::darkSectorUtilities*)
   {
      return GenerateInitInstanceLocal((::darkSectorUtilities*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::darkSectorUtilities*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_darkSectorMeson(void *p = 0);
   static void *newArray_darkSectorMeson(Long_t size, void *p);
   static void delete_darkSectorMeson(void *p);
   static void deleteArray_darkSectorMeson(void *p);
   static void destruct_darkSectorMeson(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::darkSectorMeson*)
   {
      ::darkSectorMeson *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::darkSectorMeson >(0);
      static ::ROOT::TGenericClassInfo 
         instance("darkSectorMeson", ::darkSectorMeson::Class_Version(), "darkSectorMeson.h", 9,
                  typeid(::darkSectorMeson), DefineBehavior(ptr, ptr),
                  &::darkSectorMeson::Dictionary, isa_proxy, 4,
                  sizeof(::darkSectorMeson) );
      instance.SetNew(&new_darkSectorMeson);
      instance.SetNewArray(&newArray_darkSectorMeson);
      instance.SetDelete(&delete_darkSectorMeson);
      instance.SetDeleteArray(&deleteArray_darkSectorMeson);
      instance.SetDestructor(&destruct_darkSectorMeson);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::darkSectorMeson*)
   {
      return GenerateInitInstanceLocal((::darkSectorMeson*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::darkSectorMeson*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_darkSectorVB(void *p = 0);
   static void *newArray_darkSectorVB(Long_t size, void *p);
   static void delete_darkSectorVB(void *p);
   static void deleteArray_darkSectorVB(void *p);
   static void destruct_darkSectorVB(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::darkSectorVB*)
   {
      ::darkSectorVB *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::darkSectorVB >(0);
      static ::ROOT::TGenericClassInfo 
         instance("darkSectorVB", ::darkSectorVB::Class_Version(), "darkSectorVB.h", 12,
                  typeid(::darkSectorVB), DefineBehavior(ptr, ptr),
                  &::darkSectorVB::Dictionary, isa_proxy, 4,
                  sizeof(::darkSectorVB) );
      instance.SetNew(&new_darkSectorVB);
      instance.SetNewArray(&newArray_darkSectorVB);
      instance.SetDelete(&delete_darkSectorVB);
      instance.SetDeleteArray(&deleteArray_darkSectorVB);
      instance.SetDestructor(&destruct_darkSectorVB);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::darkSectorVB*)
   {
      return GenerateInitInstanceLocal((::darkSectorVB*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::darkSectorVB*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_darkSectorDecayProbability(void *p = 0);
   static void *newArray_darkSectorDecayProbability(Long_t size, void *p);
   static void delete_darkSectorDecayProbability(void *p);
   static void deleteArray_darkSectorDecayProbability(void *p);
   static void destruct_darkSectorDecayProbability(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::darkSectorDecayProbability*)
   {
      ::darkSectorDecayProbability *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::darkSectorDecayProbability >(0);
      static ::ROOT::TGenericClassInfo 
         instance("darkSectorDecayProbability", ::darkSectorDecayProbability::Class_Version(), "darkSectorDecayProbability.h", 9,
                  typeid(::darkSectorDecayProbability), DefineBehavior(ptr, ptr),
                  &::darkSectorDecayProbability::Dictionary, isa_proxy, 4,
                  sizeof(::darkSectorDecayProbability) );
      instance.SetNew(&new_darkSectorDecayProbability);
      instance.SetNewArray(&newArray_darkSectorDecayProbability);
      instance.SetDelete(&delete_darkSectorDecayProbability);
      instance.SetDeleteArray(&deleteArray_darkSectorDecayProbability);
      instance.SetDestructor(&destruct_darkSectorDecayProbability);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::darkSectorDecayProbability*)
   {
      return GenerateInitInstanceLocal((::darkSectorDecayProbability*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::darkSectorDecayProbability*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_darkSectorFinalState(void *p = 0);
   static void *newArray_darkSectorFinalState(Long_t size, void *p);
   static void delete_darkSectorFinalState(void *p);
   static void deleteArray_darkSectorFinalState(void *p);
   static void destruct_darkSectorFinalState(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::darkSectorFinalState*)
   {
      ::darkSectorFinalState *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::darkSectorFinalState >(0);
      static ::ROOT::TGenericClassInfo 
         instance("darkSectorFinalState", ::darkSectorFinalState::Class_Version(), "darkSectorFinalState.h", 7,
                  typeid(::darkSectorFinalState), DefineBehavior(ptr, ptr),
                  &::darkSectorFinalState::Dictionary, isa_proxy, 4,
                  sizeof(::darkSectorFinalState) );
      instance.SetNew(&new_darkSectorFinalState);
      instance.SetNewArray(&newArray_darkSectorFinalState);
      instance.SetDelete(&delete_darkSectorFinalState);
      instance.SetDeleteArray(&deleteArray_darkSectorFinalState);
      instance.SetDestructor(&destruct_darkSectorFinalState);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::darkSectorFinalState*)
   {
      return GenerateInitInstanceLocal((::darkSectorFinalState*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::darkSectorFinalState*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr darkSectorTrack::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *darkSectorTrack::Class_Name()
{
   return "darkSectorTrack";
}

//______________________________________________________________________________
const char *darkSectorTrack::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::darkSectorTrack*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int darkSectorTrack::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::darkSectorTrack*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *darkSectorTrack::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::darkSectorTrack*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *darkSectorTrack::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::darkSectorTrack*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr darkSectorEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *darkSectorEvent::Class_Name()
{
   return "darkSectorEvent";
}

//______________________________________________________________________________
const char *darkSectorEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::darkSectorEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int darkSectorEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::darkSectorEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *darkSectorEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::darkSectorEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *darkSectorEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::darkSectorEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr darkSectorUtilities::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *darkSectorUtilities::Class_Name()
{
   return "darkSectorUtilities";
}

//______________________________________________________________________________
const char *darkSectorUtilities::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::darkSectorUtilities*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int darkSectorUtilities::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::darkSectorUtilities*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *darkSectorUtilities::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::darkSectorUtilities*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *darkSectorUtilities::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::darkSectorUtilities*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr darkSectorMeson::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *darkSectorMeson::Class_Name()
{
   return "darkSectorMeson";
}

//______________________________________________________________________________
const char *darkSectorMeson::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::darkSectorMeson*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int darkSectorMeson::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::darkSectorMeson*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *darkSectorMeson::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::darkSectorMeson*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *darkSectorMeson::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::darkSectorMeson*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr darkSectorVB::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *darkSectorVB::Class_Name()
{
   return "darkSectorVB";
}

//______________________________________________________________________________
const char *darkSectorVB::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::darkSectorVB*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int darkSectorVB::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::darkSectorVB*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *darkSectorVB::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::darkSectorVB*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *darkSectorVB::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::darkSectorVB*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr darkSectorDecayProbability::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *darkSectorDecayProbability::Class_Name()
{
   return "darkSectorDecayProbability";
}

//______________________________________________________________________________
const char *darkSectorDecayProbability::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::darkSectorDecayProbability*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int darkSectorDecayProbability::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::darkSectorDecayProbability*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *darkSectorDecayProbability::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::darkSectorDecayProbability*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *darkSectorDecayProbability::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::darkSectorDecayProbability*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr darkSectorFinalState::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *darkSectorFinalState::Class_Name()
{
   return "darkSectorFinalState";
}

//______________________________________________________________________________
const char *darkSectorFinalState::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::darkSectorFinalState*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int darkSectorFinalState::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::darkSectorFinalState*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *darkSectorFinalState::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::darkSectorFinalState*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *darkSectorFinalState::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::darkSectorFinalState*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void darkSectorTrack::Streamer(TBuffer &R__b)
{
   // Stream an object of class darkSectorTrack.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(darkSectorTrack::Class(),this);
   } else {
      R__b.WriteClassBuffer(darkSectorTrack::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_darkSectorTrack(void *p) {
      return  p ? new(p) ::darkSectorTrack : new ::darkSectorTrack;
   }
   static void *newArray_darkSectorTrack(Long_t nElements, void *p) {
      return p ? new(p) ::darkSectorTrack[nElements] : new ::darkSectorTrack[nElements];
   }
   // Wrapper around operator delete
   static void delete_darkSectorTrack(void *p) {
      delete ((::darkSectorTrack*)p);
   }
   static void deleteArray_darkSectorTrack(void *p) {
      delete [] ((::darkSectorTrack*)p);
   }
   static void destruct_darkSectorTrack(void *p) {
      typedef ::darkSectorTrack current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::darkSectorTrack

//______________________________________________________________________________
void darkSectorEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class darkSectorEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(darkSectorEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(darkSectorEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_darkSectorEvent(void *p) {
      return  p ? new(p) ::darkSectorEvent : new ::darkSectorEvent;
   }
   static void *newArray_darkSectorEvent(Long_t nElements, void *p) {
      return p ? new(p) ::darkSectorEvent[nElements] : new ::darkSectorEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_darkSectorEvent(void *p) {
      delete ((::darkSectorEvent*)p);
   }
   static void deleteArray_darkSectorEvent(void *p) {
      delete [] ((::darkSectorEvent*)p);
   }
   static void destruct_darkSectorEvent(void *p) {
      typedef ::darkSectorEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::darkSectorEvent

//______________________________________________________________________________
void darkSectorUtilities::Streamer(TBuffer &R__b)
{
   // Stream an object of class darkSectorUtilities.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(darkSectorUtilities::Class(),this);
   } else {
      R__b.WriteClassBuffer(darkSectorUtilities::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_darkSectorUtilities(void *p) {
      return  p ? new(p) ::darkSectorUtilities : new ::darkSectorUtilities;
   }
   static void *newArray_darkSectorUtilities(Long_t nElements, void *p) {
      return p ? new(p) ::darkSectorUtilities[nElements] : new ::darkSectorUtilities[nElements];
   }
   // Wrapper around operator delete
   static void delete_darkSectorUtilities(void *p) {
      delete ((::darkSectorUtilities*)p);
   }
   static void deleteArray_darkSectorUtilities(void *p) {
      delete [] ((::darkSectorUtilities*)p);
   }
   static void destruct_darkSectorUtilities(void *p) {
      typedef ::darkSectorUtilities current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::darkSectorUtilities

//______________________________________________________________________________
void darkSectorMeson::Streamer(TBuffer &R__b)
{
   // Stream an object of class darkSectorMeson.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(darkSectorMeson::Class(),this);
   } else {
      R__b.WriteClassBuffer(darkSectorMeson::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_darkSectorMeson(void *p) {
      return  p ? new(p) ::darkSectorMeson : new ::darkSectorMeson;
   }
   static void *newArray_darkSectorMeson(Long_t nElements, void *p) {
      return p ? new(p) ::darkSectorMeson[nElements] : new ::darkSectorMeson[nElements];
   }
   // Wrapper around operator delete
   static void delete_darkSectorMeson(void *p) {
      delete ((::darkSectorMeson*)p);
   }
   static void deleteArray_darkSectorMeson(void *p) {
      delete [] ((::darkSectorMeson*)p);
   }
   static void destruct_darkSectorMeson(void *p) {
      typedef ::darkSectorMeson current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::darkSectorMeson

//______________________________________________________________________________
void darkSectorVB::Streamer(TBuffer &R__b)
{
   // Stream an object of class darkSectorVB.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(darkSectorVB::Class(),this);
   } else {
      R__b.WriteClassBuffer(darkSectorVB::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_darkSectorVB(void *p) {
      return  p ? new(p) ::darkSectorVB : new ::darkSectorVB;
   }
   static void *newArray_darkSectorVB(Long_t nElements, void *p) {
      return p ? new(p) ::darkSectorVB[nElements] : new ::darkSectorVB[nElements];
   }
   // Wrapper around operator delete
   static void delete_darkSectorVB(void *p) {
      delete ((::darkSectorVB*)p);
   }
   static void deleteArray_darkSectorVB(void *p) {
      delete [] ((::darkSectorVB*)p);
   }
   static void destruct_darkSectorVB(void *p) {
      typedef ::darkSectorVB current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::darkSectorVB

//______________________________________________________________________________
void darkSectorDecayProbability::Streamer(TBuffer &R__b)
{
   // Stream an object of class darkSectorDecayProbability.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(darkSectorDecayProbability::Class(),this);
   } else {
      R__b.WriteClassBuffer(darkSectorDecayProbability::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_darkSectorDecayProbability(void *p) {
      return  p ? new(p) ::darkSectorDecayProbability : new ::darkSectorDecayProbability;
   }
   static void *newArray_darkSectorDecayProbability(Long_t nElements, void *p) {
      return p ? new(p) ::darkSectorDecayProbability[nElements] : new ::darkSectorDecayProbability[nElements];
   }
   // Wrapper around operator delete
   static void delete_darkSectorDecayProbability(void *p) {
      delete ((::darkSectorDecayProbability*)p);
   }
   static void deleteArray_darkSectorDecayProbability(void *p) {
      delete [] ((::darkSectorDecayProbability*)p);
   }
   static void destruct_darkSectorDecayProbability(void *p) {
      typedef ::darkSectorDecayProbability current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::darkSectorDecayProbability

//______________________________________________________________________________
void darkSectorFinalState::Streamer(TBuffer &R__b)
{
   // Stream an object of class darkSectorFinalState.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(darkSectorFinalState::Class(),this);
   } else {
      R__b.WriteClassBuffer(darkSectorFinalState::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_darkSectorFinalState(void *p) {
      return  p ? new(p) ::darkSectorFinalState : new ::darkSectorFinalState;
   }
   static void *newArray_darkSectorFinalState(Long_t nElements, void *p) {
      return p ? new(p) ::darkSectorFinalState[nElements] : new ::darkSectorFinalState[nElements];
   }
   // Wrapper around operator delete
   static void delete_darkSectorFinalState(void *p) {
      delete ((::darkSectorFinalState*)p);
   }
   static void deleteArray_darkSectorFinalState(void *p) {
      delete [] ((::darkSectorFinalState*)p);
   }
   static void destruct_darkSectorFinalState(void *p) {
      typedef ::darkSectorFinalState current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::darkSectorFinalState

namespace ROOT {
   static TClass *vectorlETLorentzVectorgR_Dictionary();
   static void vectorlETLorentzVectorgR_TClassManip(TClass*);
   static void *new_vectorlETLorentzVectorgR(void *p = 0);
   static void *newArray_vectorlETLorentzVectorgR(Long_t size, void *p);
   static void delete_vectorlETLorentzVectorgR(void *p);
   static void deleteArray_vectorlETLorentzVectorgR(void *p);
   static void destruct_vectorlETLorentzVectorgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TLorentzVector>*)
   {
      vector<TLorentzVector> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TLorentzVector>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TLorentzVector>", -2, "vector", 477,
                  typeid(vector<TLorentzVector>), DefineBehavior(ptr, ptr),
                  &vectorlETLorentzVectorgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TLorentzVector>) );
      instance.SetNew(&new_vectorlETLorentzVectorgR);
      instance.SetNewArray(&newArray_vectorlETLorentzVectorgR);
      instance.SetDelete(&delete_vectorlETLorentzVectorgR);
      instance.SetDeleteArray(&deleteArray_vectorlETLorentzVectorgR);
      instance.SetDestructor(&destruct_vectorlETLorentzVectorgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TLorentzVector> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<TLorentzVector>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETLorentzVectorgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TLorentzVector>*)0x0)->GetClass();
      vectorlETLorentzVectorgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETLorentzVectorgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETLorentzVectorgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<TLorentzVector> : new vector<TLorentzVector>;
   }
   static void *newArray_vectorlETLorentzVectorgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<TLorentzVector>[nElements] : new vector<TLorentzVector>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETLorentzVectorgR(void *p) {
      delete ((vector<TLorentzVector>*)p);
   }
   static void deleteArray_vectorlETLorentzVectorgR(void *p) {
      delete [] ((vector<TLorentzVector>*)p);
   }
   static void destruct_vectorlETLorentzVectorgR(void *p) {
      typedef vector<TLorentzVector> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TLorentzVector>

namespace {
  void TriggerDictionaryInitialization_libdarkSector_darkAnalysis_Impl() {
    static const char* headers[] = {
"darkSectorDecayProbability.h",
"darkSectorEvent.h",
"darkSectorFinalState.h",
"darkSectorMeson.h",
"darkSectorTrack.h",
"darkSectorUtilities.h",
"darkSectorVB.h",
0
    };
    static const char* includePaths[] = {
"/Users/br/BasicSoftware/root-6.04.12/include",
"/Users/br/BasicSoftware/larlite/UserDev/darkAnalysis/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$darkSectorDecayProbability.h")))  darkSectorTrack;
class __attribute__((annotate("$clingAutoload$darkSectorEvent.h")))  darkSectorEvent;
class __attribute__((annotate("$clingAutoload$darkSectorUtilities.h")))  darkSectorUtilities;
class __attribute__((annotate("$clingAutoload$darkSectorMeson.h")))  darkSectorMeson;
class __attribute__((annotate("$clingAutoload$darkSectorVB.h")))  darkSectorVB;
class __attribute__((annotate("$clingAutoload$darkSectorDecayProbability.h")))  darkSectorDecayProbability;
class __attribute__((annotate("$clingAutoload$darkSectorFinalState.h")))  darkSectorFinalState;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "darkSectorDecayProbability.h"
#include "darkSectorEvent.h"
#include "darkSectorFinalState.h"
#include "darkSectorMeson.h"
#include "darkSectorTrack.h"
#include "darkSectorUtilities.h"
#include "darkSectorVB.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"darkSectorDecayProbability", payloadCode, "@",
"darkSectorEvent", payloadCode, "@",
"darkSectorFinalState", payloadCode, "@",
"darkSectorMeson", payloadCode, "@",
"darkSectorTrack", payloadCode, "@",
"darkSectorUtilities", payloadCode, "@",
"darkSectorVB", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libdarkSector_darkAnalysis",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libdarkSector_darkAnalysis_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libdarkSector_darkAnalysis_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libdarkSector_darkAnalysis() {
  TriggerDictionaryInitialization_libdarkSector_darkAnalysis_Impl();
}

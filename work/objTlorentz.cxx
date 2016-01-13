{
   // File: tobjarray_example.cc
   //
   // Using TObjArray class
   // ~~~~~~~~~~~~~~~~~~~~~
   //
   // This approach should work with any root object which derives from the
   // TObject class. Here we use TLorentzVector objects
   //
   // To use, run root and at the prompt type
   //               .x tobjarray_example.cc
   //
   // Declaration:
 
#include <TObjArray.h>
 
   TObjArray* object_list = new TObjArray();
 
   // Adding something to the list:
 
   TLorentzVector v1(0., 0., 0., .1395);
   TLorentzVector v2(0., 0., 0., .938);
   TLorentzVector v3(0., 0., 0., 1.777);
 
   TLorentzVector* p1 = &v1;
   TLorentzVector* p2 = &v2;
   TLorentzVector* p3 = &v3;
 
   object_list->AddLast(p1);
   object_list->AddLast(p2);
   object_list->AddLast(p3);
 
   // Looping through list. (Note we cast the object to the type we need)
 
   TObjArrayIter next(object_list);
   TObject* object;
   while ( ( object = next() ) ) {
        // Do something with object
        TLorentzVector* p = (TLorentzVector*) object;
        std::cout << "Mass is: " << p->M() << std::endl;
   }
 
}

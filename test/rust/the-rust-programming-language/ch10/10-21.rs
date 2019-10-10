/*
 * Lifetime annotations don't change how long any of the references live. Just as functions can 
 * accept any type when the signature specifies a generic type parameter, functions can accept 
 * references with any lifetime by specifying a generic lifetime parameter. Lifetime annotation
 * describe the relationships of the lifetimes of multiple references to each other without 
 * affecting the lifetimes.
 * 
 * Lifetime annotations have a slightly unused syntax: the names of lifetime parameters must start
 * with an apostrophe (') and are usually all lowercase and very short, like generic types. Most 
 * people use the name 'a. We place lifetime parameter annotations after the & of a reference, using 
 * a space to separate the annotation from the reference's typs.
 */
&i32        // a reference
&'a i32     // a reference with an explicti lifetime
&'a mut i32 // a mutable reference with an explicit lifetime

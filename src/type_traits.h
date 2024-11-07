//этот хэдер должен быть в стандартной библиотке
//НО ПОЧЕМУ-ТО ЕГО ТАМ НЕТ. так что вот
namespace std {
  // helper class
  template<class T, T v> struct integral_constant;
 
  template<bool B>
    using bool_constant = integral_constant<bool, B>;
  using true_type  = bool_constant<true>;
  using false_type = bool_constant<false>;
 
  // primary type categories
  template<class T> struct is_void;
  template<class T> struct is_null_pointer;
  template<class T> struct is_integral;
  template<class T> struct is_floating_point;
  template<class T> struct is_array;
  template<class T> struct is_pointer;
  template<class T> struct is_lvalue_reference;
  template<class T> struct is_rvalue_reference;
  template<class T> struct is_member_object_pointer;
  template<class T> struct is_member_function_pointer;
  template<class T> struct is_enum;
  template<class T> struct is_union;
  template<class T> struct is_class;
  template<class T> struct is_function;
 
  // composite type categories
  template<class T> struct is_reference;
  template<class T> struct is_arithmetic;
  template<class T> struct is_fundamental;
  template<class T> struct is_object;
  template<class T> struct is_scalar;
  template<class T> struct is_compound;
  template<class T> struct is_member_pointer;
 
  // type properties
  template<class T> struct is_const;
  template<class T> struct is_volatile;
  template<class T> struct is_trivial;
  template<class T> struct is_trivially_copyable;
  template<class T> struct is_standard_layout;
  template<class T> struct is_empty;
  template<class T> struct is_polymorphic;
  template<class T> struct is_abstract;
  template<class T> struct is_final;
  template<class T> struct is_aggregate;
 
  template<class T> struct is_signed;
  template<class T> struct is_unsigned;
  template<class T> struct is_bounded_array;
  template<class T> struct is_unbounded_array;
  template<class T> struct is_scoped_enum;
 
  template<class T, class... Args> struct is_constructible;
  template<class T> struct is_default_constructible;
  template<class T> struct is_copy_constructible;
  template<class T> struct is_move_constructible;
 
  template<class T, class U> struct is_assignable;
  template<class T> struct is_copy_assignable;
  template<class T> struct is_move_assignable;
 
  template<class T, class U> struct is_swappable_with;
  template<class T> struct is_swappable;
 
  template<class T> struct is_destructible;
 
  template<class T, class... Args> struct is_trivially_constructible;
  template<class T> struct is_trivially_default_constructible;
  template<class T> struct is_trivially_copy_constructible;
  template<class T> struct is_trivially_move_constructible;
 
  template<class T, class U> struct is_trivially_assignable;
  template<class T> struct is_trivially_copy_assignable;
  template<class T> struct is_trivially_move_assignable;
  template<class T> struct is_trivially_destructible;
 
  template<class T, class... Args> struct is_nothrow_constructible;
  template<class T> struct is_nothrow_default_constructible;
  template<class T> struct is_nothrow_copy_constructible;
  template<class T> struct is_nothrow_move_constructible;
 
  template<class T, class U> struct is_nothrow_assignable;
  template<class T> struct is_nothrow_copy_assignable;
  template<class T> struct is_nothrow_move_assignable;
 
  template<class T, class U> struct is_nothrow_swappable_with;
  template<class T> struct is_nothrow_swappable;
 
  template<class T> struct is_nothrow_destructible;
 
  template<class T> struct has_virtual_destructor;
 
  template<class T> struct has_unique_object_representations;
 
  template<class T, class U> struct reference_constructs_from_temporary;
  template<class T, class U> struct reference_converts_from_temporary;
 
  // type property queries
  template<class T> struct alignment_of;
  template<class T> struct rank;
  template<class T, unsigned I = 0> struct extent;
 
  // type relations
  template<class T, class U> struct is_same;
  template<class Base, class Derived> struct is_base_of;
  template<class Base, class Derived> struct is_virtual_base_of;
  template<class From, class To> struct is_convertible;
  template<class From, class To> struct is_nothrow_convertible;
  template<class T, class U> struct is_layout_compatible;
  template<class Base, class Derived> struct is_pointer_interconvertible_base_of;
 
  template<class Fn, class... ArgTypes> struct is_invocable;
  template<class R, class Fn, class... ArgTypes> struct is_invocable_r;
 
  template<class Fn, class... ArgTypes> struct is_nothrow_invocable;
  template<class R, class Fn, class... ArgTypes> struct is_nothrow_invocable_r;
 
  // const-volatile modifications
  template<class T> struct remove_const;
  template<class T> struct remove_volatile;
  template<class T> struct remove_cv;
  template<class T> struct add_const;
  template<class T> struct add_volatile;
  template<class T> struct add_cv;
 
  template<class T>
    using remove_const_t    = typename remove_const<T>::type;
  template<class T>
    using remove_volatile_t = typename remove_volatile<T>::type;
  template<class T>
    using remove_cv_t       = typename remove_cv<T>::type;
  template<class T>
    using add_const_t       = typename add_const<T>::type;
  template<class T>
    using add_volatile_t    = typename add_volatile<T>::type;
  template<class T>
    using add_cv_t          = typename add_cv<T>::type;
 
  // reference modifications
  template<class T> struct remove_reference;
  template<class T> struct add_lvalue_reference;
  template<class T> struct add_rvalue_reference;
 
  template<class T>
    using remove_reference_t     = typename remove_reference<T>::type;
  template<class T>
    using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;
  template<class T>
    using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;
 
  // sign modifications
  template<class T> struct make_signed;
  template<class T> struct make_unsigned;
 
  template<class T>
    using make_signed_t   = typename make_signed<T>::type;
  template<class T>
    using make_unsigned_t = typename make_unsigned<T>::type;
 
  // array modifications
  template<class T> struct remove_extent;
  template<class T> struct remove_all_extents;
 
  template<class T>
    using remove_extent_t      = typename remove_extent<T>::type;
  template<class T>
    using remove_all_extents_t = typename remove_all_extents<T>::type;
 
  // pointer modifications
  template<class T> struct remove_pointer;
  template<class T> struct add_pointer;
 
  template<class T>
    using remove_pointer_t = typename remove_pointer<T>::type;
  template<class T>
    using add_pointer_t    = typename add_pointer<T>::type;
 
  // other transformations
  template<class T> struct type_identity;
  template<class T> struct remove_cvref;
  template<class T> struct decay;
  template<bool, class T = void> struct enable_if;
  template<bool, class T, class F> struct conditional;
  template<class... T> struct common_type;
  template<class T, class U, template<class> class TQual, template<class> class UQual>
    struct basic_common_reference { };
  template<class... T> struct common_reference;
  template<class T> struct underlying_type;
  template<class Fn, class... ArgTypes> struct invoke_result;
  template<class T> struct unwrap_reference;
  template<class T> struct unwrap_ref_decay;
 
  template<class T>
    using type_identity_t    = typename type_identity<T>::type;
  template<class T>
    using remove_cvref_t     = typename remove_cvref<T>::type;
  template<class T>
    using decay_t            = typename decay<T>::type;
  template<bool b, class T = void>
    using enable_if_t        = typename enable_if<b, T>::type;
  template<bool b, class T, class F>
    using conditional_t      = typename conditional<b, T, F>::type;
  template<class... T>
    using common_type_t      = typename common_type<T...>::type;
  template<class... T>
    using common_reference_t = typename common_reference<T...>::type;
  template<class T>
    using underlying_type_t  = typename underlying_type<T>::type;
  template<class Fn, class... ArgTypes>
    using invoke_result_t    = typename invoke_result<Fn, ArgTypes...>::type;
  template<class T>
    using unwrap_reference_t = typename unwrap_reference<T>::type;
  template<class T>
    using unwrap_ref_decay_t = typename unwrap_ref_decay<T>::type;
  template<class...>
    using void_t             = void;
 
  // logical operator traits
  template<class... B> struct conjunction;
  template<class... B> struct disjunction;
  template<class B> struct negation;
}
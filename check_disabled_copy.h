/// BEGIN Du behöver inte förstå nedan kod
/// Om koden orsakar bekymmer kommenterar du ut includen och anropet i main
template<typename T>
auto check_disabled_copy(T, int, int)->decltype(T{std::declval<T>()}, std::declval<void>())
{
  std::cout << "ERROR: Found copy constructor" << std::endl;
}

template<typename T>
auto check_disabled_copy(T& t, int, unsigned)->decltype(t.operator=(t), std::declval<void>())
{
  std::cout << "ERROR: Found assignment operator" << std::endl;
}

template<typename T>
auto check_disabled_copy(T&, unsigned, unsigned)->void
{
  std::cout << "OK" << std::endl;
}
/// END Du behöver inte förstå ovan kod

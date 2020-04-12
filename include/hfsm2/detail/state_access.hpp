namespace hfsm2 {
namespace detail {

#ifndef HFSM_EXPLICIT_MEMBER_SPECIALIZATION

//------------------------------------------------------------------------------

template <typename...>
struct Accessor;

////////////////////////////////////////////////////////////////////////////////

template <typename T,
		  typename TN,
		  typename TA,
		  Strategy TG,
		  typename TH,
		  typename... TS>
struct Accessor<T,		 C_<TN, TA, TG, TH, TS...>> {
	using Host =		 C_<TN, TA, TG, TH, TS...>;

	HFSM_INLINE		  T& get()			{ return Accessor<T,	   typename Host::SubStates>{host._subStates}.get();	}

	Host& host;
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename T,
		  typename TN,
		  typename TA,
		  Strategy TG,
		  typename TH,
		  typename... TS>
struct Accessor<T, const C_<TN, TA, TG, TH, TS...>> {
	using Host =   const C_<TN, TA, TG, TH, TS...>;

	HFSM_INLINE const T& get() const	{ return Accessor<T, const typename Host::SubStates>{host._subStates}.get();	}

	Host& host;
};

//------------------------------------------------------------------------------

template <typename T,
		  typename TN,
		  typename TA,
		  Strategy TG,
		  typename... TS>
struct Accessor<T,		 C_<TN, TA, TG,  T, TS...>> {
	using Host =		 C_<TN, TA, TG,  T, TS...>;

	HFSM_INLINE		  T& get()			{ return host._headState._head;				}

	Host& host;
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename T,
		  typename TN,
		  typename TA,
		  Strategy TG,
		  typename... TS>
struct Accessor<T, const C_<TN, TA, TG,  T, TS...>> {
	using Host =   const C_<TN, TA, TG,  T, TS...>;

	HFSM_INLINE const T& get() const	{ return host._headState._head;				}

	Host& host;
};

////////////////////////////////////////////////////////////////////////////////

template <typename T,
		  typename TN,
		  typename TA,
		  Strategy TG,
		  ShortIndex NI,
		  typename... TS>
struct Accessor<T,		 CS_<TN, TA, TG, NI, TS...>> {
	using Host =		 CS_<TN, TA, TG, NI, TS...>;

	HFSM_INLINE		  T& get()		 {
		return Host::LHalfInfo::StateList::template contains<T>() ?
			Accessor<T,		  typename Host::LHalf>{host.lHalf}.get() :
			Accessor<T,		  typename Host::RHalf>{host.rHalf}.get();
	}

	Host& host;
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename T,
		  typename TN,
		  typename TA,
		  Strategy TG,
		  ShortIndex NI,
		  typename... TS>
struct Accessor<T, const CS_<TN, TA, TG, NI, TS...>> {
	using Host =   const CS_<TN, TA, TG, NI, TS...>;

	HFSM_INLINE const T& get() const {
		return Host::LHalfInfo::StateList::template contains<T>() ?
			Accessor<T, const typename Host::LHalf>{host.lHalf}.get() :
			Accessor<T, const typename Host::RHalf>{host.rHalf}.get();
	}

	Host& host;
};

//------------------------------------------------------------------------------

template <typename T,
		  typename TN,
		  typename TA,
		  Strategy TG,
		  ShortIndex NI,
		  typename TS>
struct Accessor<T,		 CS_<TN, TA, TG, NI, TS>> {
	using Host =		 CS_<TN, TA, TG, NI, TS>;

	HFSM_INLINE		  T& get()			{ return Accessor<T,	   typename Host::State>{host.state}.get();		}

	Host& host;
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename T,
		  typename TN,
		  typename TA,
		  Strategy TG,
		  ShortIndex NI,
		  typename TS>
struct Accessor<T, const CS_<TN, TA, TG, NI, TS>> {
	using Host =   const CS_<TN, TA, TG, NI, TS>;

	HFSM_INLINE const T& get() const	{ return Accessor<T, const typename Host::State>{host.state}.get();		}

	Host& host;
};

////////////////////////////////////////////////////////////////////////////////

template <typename T,
		  typename TN,
		  typename TA,
		  typename TH,
		  typename... TS>
struct Accessor<T,		 O_<TN, TA, TH, TS...>> {
	using Host =		 O_<TN, TA, TH, TS...>;

	HFSM_INLINE		  T& get()			{ return Accessor<T,	   typename Host::SubStates>{host._subStates}.get();	}

	Host& host;
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename T,
		  typename TN,
		  typename TA,
		  typename TH,
		  typename... TS>
struct Accessor<T, const O_<TN, TA, TH, TS...>> {
	using Host =   const O_<TN, TA, TH, TS...>;

	HFSM_INLINE const T& get() const	{ return Accessor<T, const typename Host::SubStates>{host._subStates}.get();	}

	Host& host;
};

//------------------------------------------------------------------------------

template <typename T,
		  typename TN,
		  typename TA,
		  typename... TS>
struct Accessor<T,		 O_<TN, TA,  T, TS...>> {
	using Host =		 O_<TN, TA,  T, TS...>;

	HFSM_INLINE		  T& get()			{ return host._headState._head;				}

	Host& host;
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename T,
		  typename TN,
		  typename TA,
		  typename... TS>
struct Accessor<T, const O_<TN, TA,  T, TS...>> {
	using Host =   const O_<TN, TA,  T, TS...>;

	HFSM_INLINE const T& get() const	{ return host._headState._head;				}

	Host& host;
};

////////////////////////////////////////////////////////////////////////////////

template <typename T,
		  typename TN,
		  typename TA,
		  ShortIndex NI,
		  typename... TS>
struct Accessor<T,		 OS_<TN, TA, NI, TS...>> {
	using Host =		 OS_<TN, TA, NI, TS...>;

	HFSM_INLINE		  T& get()		 {
		return Host::InitialStates::template contains<T>() ?
			Accessor<T,		  typename Host::Initial  >{host.initial  }.get() :
			Accessor<T,		  typename Host::Remaining>{host.remaining}.get();
	}

	Host& host;
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename T,
		  typename TN,
		  typename TA,
		  ShortIndex NI,
		  typename... TS>
struct Accessor<T, const OS_<TN, TA, NI, TS...>> {
	using Host =   const OS_<TN, TA, NI, TS...>;

	HFSM_INLINE const T& get() const {
		return Host::InitialStates::template contains<T>() ?
			Accessor<T, const typename Host::Initial  >{host.initial  }.get() :
			Accessor<T, const typename Host::Remaining>{host.remaining}.get();
	}

	Host& host;
};

//------------------------------------------------------------------------------

template <typename T,
		  typename TN,
		  typename TA,
		  ShortIndex NI,
		  typename TS>
struct Accessor<T,		 OS_<TN, TA, NI, TS>> {
	using Host =		 OS_<TN, TA, NI, TS>;

	HFSM_INLINE		  T& get()			{ return Accessor<T,	   typename Host::Initial>{host.initial  }.get();	}

	Host& host;
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename T,
		  typename TN,
		  typename TA,
		  ShortIndex NI,
		  typename TS>
struct Accessor<T, const OS_<TN, TA, NI, TS>> {
	using Host =   const OS_<TN, TA, NI, TS>;

	HFSM_INLINE const T& get() const	{ return Accessor<T, const typename Host::Initial>{host.initial  }.get();	}

	Host& host;
};

////////////////////////////////////////////////////////////////////////////////

#ifdef __clang__
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wnull-dereference"
#endif

template <typename T,
		  typename TN,
		  typename TA,
		  typename TH>
struct Accessor<T,		 S_<TN, TA, TH>> {
	using Host =		 S_<TN, TA, TH>;

	HFSM_INLINE		  T& get()			{ HFSM_BREAK(); return *reinterpret_cast<T*>(0);	}

	Host& host;
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename T,
		  typename TN,
		  typename TA,
		  typename TH>
struct Accessor<T, const S_<TN, TA, TH>> {
	using Host =   const S_<TN, TA, TH>;

	HFSM_INLINE const T& get() const	{ HFSM_BREAK(); return *reinterpret_cast<T*>(0);	}

	Host& host;
};

#ifdef __clang__
	#pragma clang diagnostic pop
#endif

//------------------------------------------------------------------------------

template <typename T,
		  typename TN,
		  typename TA>
struct Accessor<T,		 S_<TN, TA,  T>> {
	using Host =		 S_<TN, TA,  T>;

	HFSM_INLINE		  T& get()			{ return host._head;								}

	Host& host;
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename T,
		  typename TN,
		  typename TA>
struct Accessor<T, const S_<TN, TA,  T>> {
	using Host =   const S_<TN, TA,  T>;

	HFSM_INLINE const T& get() const	{ return host._head;								}

	Host& host;
};

////////////////////////////////////////////////////////////////////////////////

#endif

}
}

/* TODO:
 * USING -> STRUCT
 */

#include <assert.h>
#include <vector>
#include <iostream>

#include <FOSL/physics.hpp>

#define __FOSL_DEFINE_FUNDEMENTAL_UNIT(name)                                  \
	template< int _dimension = 0                                              \
	        , int _scale     = 1                                              \
	        , int _offset    = 0>                                             \
	struct name                                                               \
	{                                                                         \
		static constexpr int dimension = _dimension;                          \
		static constexpr int scale     = _scale;                              \
		static constexpr int offset    = _offset;                             \
	                                                                          \
		static constexpr unsigned int magic = __COUNTER__;                    \
	};                                                                        \
	                                                                          \
	template <typename type> concept type_of_##name = type::magic == __COUNTER__ - 1;

namespace FOSL::physics
{
	namespace part
	{
		__FOSL_DEFINE_FUNDEMENTAL_UNIT(metre)
		__FOSL_DEFINE_FUNDEMENTAL_UNIT(kilogram)
		__FOSL_DEFINE_FUNDEMENTAL_UNIT(second)
		__FOSL_DEFINE_FUNDEMENTAL_UNIT(ampere)
		__FOSL_DEFINE_FUNDEMENTAL_UNIT(kelvin)
		__FOSL_DEFINE_FUNDEMENTAL_UNIT(candela)
		__FOSL_DEFINE_FUNDEMENTAL_UNIT(mole)
	}

	// template< int _dimension = 0
	//         , int _scale     = 1
	//         , int _offset    = 0>
	// struct metre
	// {
	// 	static constexpr int dimension = _dimension;
	// 	static constexpr int scale     = _scale;
	// 	static constexpr int offset    = _offset;

	// 	static constexpr unsigned int index = 0;
	// };

	// template <typename type> concept type_of_metre    = type::index == 0;
	// template <typename type> concept type_of_kilogram = type::index == 1;
	// template <typename type> concept type_of_second   = type::index == 2;
	// template <typename type> concept type_of_ampere   = type::index == 3;
	// template <typename type> concept type_of_kelvin   = type::index == 4;
	// template <typename type> concept type_of_candela  = type::index == 5;
	// template <typename type> concept type_of_mole     = type::index == 6;

	template< part::type_of_metre    _metre
			, part::type_of_kilogram _kilogram
			, part::type_of_second   _second
			, part::type_of_ampere   _ampere
			, part::type_of_kelvin   _kelvin
			, part::type_of_candela  _candela
			, part::type_of_mole     _mole >
	struct unit
	{
		using metre    = _metre;
		using kilogram = _kilogram;
		using second   = _second;
		using ampere   = _ampere;
		using kelvin   = _kelvin;
		using candela  = _candela;
		using mole     = _mole;
	};
	template <typename type>
	concept type_of_unit = true;

	template< type_of_unit lhs_unit
			, type_of_unit rhs_unit >
	auto operator/( lhs_unit lhs
				  , rhs_unit rhs )
		-> unit< part::metre   <lhs_unit::metre   ::dimension - rhs_unit::metre   ::dimension, lhs_unit::metre   ::scale, lhs_unit::metre   ::offset>
			   , part::kilogram<lhs_unit::kilogram::dimension - rhs_unit::kilogram::dimension, lhs_unit::kilogram::scale, lhs_unit::kilogram::offset>
			   , part::second  <lhs_unit::second  ::dimension - rhs_unit::second  ::dimension, lhs_unit::second  ::scale, lhs_unit::second  ::offset>
			   , part::ampere  <lhs_unit::ampere  ::dimension - rhs_unit::ampere  ::dimension, lhs_unit::ampere  ::scale, lhs_unit::ampere  ::offset>
			   , part::kelvin  <lhs_unit::kelvin  ::dimension - rhs_unit::kelvin  ::dimension, lhs_unit::kelvin  ::scale, lhs_unit::kelvin  ::offset>
			   , part::candela <lhs_unit::candela ::dimension - rhs_unit::candela ::dimension, lhs_unit::candela ::scale, lhs_unit::candela ::offset>
			   , part::mole    <lhs_unit::mole    ::dimension - rhs_unit::mole    ::dimension, lhs_unit::mole    ::scale, lhs_unit::mole    ::offset> >
	{
		return {};
	}

	template< type_of_unit lhs_unit
			, type_of_unit rhs_unit >
	auto operator-( lhs_unit lhs
				  , rhs_unit rhs )
		-> unit< part::metre   <lhs_unit::metre   ::dimension, lhs_unit::metre   ::scale, lhs_unit::metre   ::offset>
			   , part::kilogram<lhs_unit::kilogram::dimension, lhs_unit::kilogram::scale, lhs_unit::kilogram::offset>
			   , part::second  <lhs_unit::second  ::dimension, lhs_unit::second  ::scale, lhs_unit::second  ::offset>
			   , part::ampere  <lhs_unit::ampere  ::dimension, lhs_unit::ampere  ::scale, lhs_unit::ampere  ::offset>
			   , part::kelvin  <lhs_unit::kelvin  ::dimension, lhs_unit::kelvin  ::scale, lhs_unit::kelvin  ::offset>
			   , part::candela <lhs_unit::candela ::dimension, lhs_unit::candela ::scale, lhs_unit::candela ::offset>
			   , part::mole    <lhs_unit::mole    ::dimension, lhs_unit::mole    ::scale, lhs_unit::mole    ::offset> >
	{
		return {};
	}

	using metre = unit< part::metre   <1>
					  , part::kilogram< >
					  , part::second  < >
					  , part::ampere  < >
					  , part::kelvin  < >
					  , part::candela < >
					  , part::mole    < > >;
	using kilogram = unit< part::metre   < >
						 , part::kilogram<1>
						 , part::second  < >
						 , part::ampere  < >
						 , part::kelvin  < >
						 , part::candela < >
						 , part::mole    < > >;
	using second = unit< part::metre   < >
					   , part::kilogram< >
					   , part::second  <1>
					   , part::ampere  < >
					   , part::kelvin  < >
					   , part::candela < >
					   , part::mole    < > >;
	using ampere = unit< part::metre   < >
					   , part::kilogram< >
					   , part::second  < >
					   , part::ampere  <1>
					   , part::kelvin  < >
					   , part::candela < >
					   , part::mole    < > >;
	using kelvin = unit< part::metre   < >
					   , part::kilogram< >
					   , part::second  < >
					   , part::ampere  < >
					   , part::kelvin  <1>
					   , part::candela < >
					   , part::mole    < > >;
	using candela = unit< part::metre   < >
						, part::kilogram< >
						, part::second  < >
						, part::ampere  < >
						, part::kelvin  < >
						, part::candela <1>
						, part::mole    < > >;
	using mole = unit< part::metre   < >
					 , part::kilogram< >
					 , part::second  < >
					 , part::ampere  < >
					 , part::kelvin  < >
					 , part::candela < >
					 , part::mole    <1> >;

	// struct metre : unit< part::metre   <1>
	//                    , part::kilogram< >
	//                    , part::second  < >
	//                    , part::ampere  < >
	//                    , part::kelvin  < >
	//                    , part::candela < >
	//                    , part::mole    < > >
	// {
	// 	using metre    = unit::metre;
	// 	using kilogram = unit::kilogram;
	// 	using second   = unit::second;
	// 	using ampere   = unit::ampere;
	// 	using kelvin   = unit::kelvin;
	// 	using candela  = unit::candela;
	// 	using mole     = unit::mole;
	// };
	// struct kilogram : unit< part::metre   < >
	//                       , part::kilogram<1>
	//                       , part::second  < >
	//                       , part::ampere  < >
	//                       , part::kelvin  < >
	//                       , part::candela < >
	//                       , part::mole    < > >
	// {};
	// struct second : unit< part::metre   < >
	//                     , part::kilogram< >
	//                     , part::second  <1>
	//                     , part::ampere  < >
	//                     , part::kelvin  < >
	//                     , part::candela < >
	//                     , part::mole    < > >
	// {};
	// struct ampere : unit< part::metre   < >
	//                     , part::kilogram< >
	//                     , part::second  < >
	//                     , part::ampere  <1>
	//                     , part::kelvin  < >
	//                     , part::candela < >
	//                     , part::mole    < > >
	// {};
	// struct kelvin : unit< part::metre   < >
	//                     , part::kilogram< >
	//                     , part::second  < >
	//                     , part::ampere  < >
	//                     , part::kelvin  <1>
	//                     , part::candela < >
	//                     , part::mole    < > >
	// {};
	// struct candela : unit< part::metre   < >
	//                      , part::kilogram< >
	//                      , part::second  < >
	//                      , part::ampere  < >
	//                      , part::kelvin  < >
	//                      , part::candela <1>
	//                      , part::mole    < > >
	// {};
	// struct mole : unit< part::metre   < >
	//                   , part::kilogram< >
	//                   , part::second  < >
	//                   , part::ampere  < >
	//                   , part::kelvin  < >
	//                   , part::candela < >
	//                   , part::mole    <1> >
	// {};

	template< type_of_unit _unit_type
			, typename    _value_type = double >
	struct quantity
	{
		using  unit_type =  _unit_type;
		using value_type = _value_type;

		value_type value;
	};
	template <typename type>
	concept type_of_quantity = requires (type value)
	{
		{ value.value };
	};

	template<type_of_quantity quantity> auto
	operator-( quantity lhs
			 , quantity rhs )
		-> quantity
	{
		return { lhs.value - rhs.value };
	}

	template< type_of_quantity lhs_quantity
			, type_of_quantity rhs_quantity > auto
	operator/( lhs_quantity lhs
			 , rhs_quantity rhs )
		-> quantity<decltype(typename lhs_quantity::unit_type{} / typename rhs_quantity::unit_type{}), typename lhs_quantity::value_type>
	{
		return { lhs.value / rhs.value };
	}

	template <typename value_type = double>
	using length = quantity<metre, value_type>;
	template <typename value_type = double>
	using distance = quantity<decltype(metre{} - metre{}), value_type>;
	template <typename value_type = double>
	using time = quantity<second, value_type>;
	template <typename value_type = double>
	using velocity = quantity<decltype(metre{} / second{}), value_type>;
}

int main(void)
{
	using namespace FOSL;
	using namespace FOSL::physics;
	{
		physics::length<> l[2] = { 2, 5 };
		physics::time<>   t[2] = { 0, 1 };

		physics::velocity<> v = (l[1] - l[0])
		                      / (t[1] - t[0]);

		std::cout << "velocity: " << v.value << " m/s" << '\n';
	}
}

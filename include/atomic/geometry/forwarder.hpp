#pragma once 
#ifndef ATOMIC_GEOMETRY_GEOMETRY_FORWARDER_HPP
#define ATOMIC_GEOMETRY_GEOMETRY_FORWARDER_HPP

#include <atomic/core/utility.hpp>
#include <cstdlib>

namespace atomic { namespace geometry {

template<typename T, std::size_t D>
struct line;

template<typename T, std::size_t D>
struct ray;

template<typename T, std::size_t D>
struct line_segment;

template<typename T>
struct circle;

template<typename T>
struct triangle;

}} // atomic::geometry namespace

#endif // ATOMIC_GEOMETRY_GEOMETRY_FORWARDER_HPP
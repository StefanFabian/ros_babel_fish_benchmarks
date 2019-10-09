//
// Created by Stefan Fabian on 18.09.19.
//

#include <benchmark/benchmark.h>
#include <ros_babel_fish/generation/providers/integrated_description_provider.h>

static void IntegratedDescriptionProviderCreate( benchmark::State &state )
{
  for ( auto _ : state )
  {
    ros_babel_fish::IntegratedDescriptionProvider provider;
  }
}

BENCHMARK( IntegratedDescriptionProviderCreate )->Unit( benchmark::kMillisecond );

static void IntegratedDescriptionProviderLookUp( benchmark::State &state )
{
  for ( auto _ : state )
  {
    state.PauseTiming();
    ros_babel_fish::IntegratedDescriptionProvider provider;
    state.ResumeTiming();
    if ( provider.getMessageDescription( "ros_babel_fish_test_msgs/TestArray" ) == nullptr )
      throw std::runtime_error( "Message description was nullptr!" );
  }
}

BENCHMARK( IntegratedDescriptionProviderLookUp )->Unit( benchmark::kMicrosecond );


BENCHMARK_MAIN();
using Sharpmake;

[module: Include("atrium/sharpmake.cs")]
[module: Include("iris/sharpmake.cs")]

namespace Iris
{
	[Generate]
	public class IrisSolution : Solution
	{
		public IrisSolution()
		{
			Name = "Iris";

			AddTargets(new Target(
				Platform.win64,
				DevEnv.vs2022,
				Util.AllFlags<Optimization>()
			));
		}

		[Configure]
		public void ConfigureAll(Configuration conf, Target target)
		{
			Util.SetDefaultBuildArguments(conf, target);
			conf.AddProject<IrisExecutable>(target);
		}
	}
}

public static class Main
{
	[Sharpmake.Main]
	public static void SharpmakeMain(Arguments arguments)
	{
		arguments.Generate<Iris.IrisSolution>();
	}
}
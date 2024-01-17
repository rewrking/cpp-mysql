#include "Application.hpp"

#include "Libraries/Format.hpp"
#include "Libraries/JSON.hpp"

namespace sapp
{
/*****************************************************************************/
sql::Session Application::getSession(const DbConfig& inConfig) const
{
	return sql::Session(inConfig.getSessionSettings());
}

/*****************************************************************************/
i32 Application::run(i32 argc, const char* const argv[])
{
	SAPP_TRY
	{
		UNUSED(argc, argv);

		auto config = DbConfig::get();

		std::cout << fmt::format("Creating session on: {}", config.getHostName()) << std::endl;

		auto sess = getSession(config);

		std::cout << "Session accepted, creating collection..." << std::endl;

		auto db = sess.getSchema(config.db());
		auto coll = db.createCollection("test_data", true);

		std::cout << "Inserting documents..." << std::endl;

		// Remove the old collection
		coll.remove("true").execute();

		{
			Json data;
			data["name"] = "The Hobbit";
			data["author"] = "J.R.R. Tolkien";
			data["year"] = "1937";

			auto add = coll.add(data.dump()).execute();
			auto ids = add.getGeneratedIds();
			for (auto& id : ids)
			{
				std::cout << fmt::format("- added doc with id: {}\n", id);
			}
		}
	}
	SAPP_CATCH(const std::exception& err)
	{
		std::cerr << err.what() << std::endl;
		return SAPP_EXIT_FAILURE;
	}

	return SAPP_EXIT_SUCCESS;
}
}
